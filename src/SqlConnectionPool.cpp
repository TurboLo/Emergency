
#include "SqlConnectionPool.h"
#include <QApplication>
#include <QSettings>
#include <qDebug>
QMutex SqlConnectionPool::m_mutex;
QWaitCondition SqlConnectionPool::m_waitCondition;
SqlConnectionPool::SqlConnectionPool()
{
	qDebug() <<  QSqlDatabase::drivers();
	m_settingPath = QApplication::applicationDirPath() + "/config/config.ini";
	QSettings settings(m_settingPath,QSettings::IniFormat);
	m_dataBaseType = settings.value("Sql/dataBaseType").toString();
	if (m_dataBaseType == "QSQLITE")
	{
		m_dataBaseName = QApplication::applicationDirPath() + "/" + settings.value("Sql/dataBaseName").toString();
	}
	else
	{
		m_hostName = settings.value("Sql/hostName").toString();
		m_userName = settings.value("Sql/userName").toString();
		m_password = settings.value("Sql/password").toString();
		m_dataBaseName = settings.value("Sql/dataBaseName").toString();
	}
	m_maxWaitTime = 1000;
	m_waitInterval = 200;
	m_maxConnectionCount = 1000;
}

SqlConnectionPool::~SqlConnectionPool()
{
	for(const auto &connectionName:m_usedConnectionNames)
	{
		QSqlDatabase::removeDatabase(connectionName);
	}
}

QSqlDatabase SqlConnectionPool::openConnection()
{
	SqlConnectionPool& pool = SqlConnectionPool::getInstance();
	QString connectionName;
	QMutexLocker locker(&m_mutex);

	int connectionCount = pool.m_unusedConnectionNames.size() + pool.m_usedConnectionNames.size();

	for (int i =0; i < pool.m_maxWaitTime && pool.m_unusedConnectionNames.empty() && connectionCount == pool.m_maxConnectionCount;i+pool.m_waitInterval)
	{
		m_waitCondition.wait(&m_mutex, pool.m_waitInterval);

		connectionCount = pool.m_unusedConnectionNames.size() + pool.m_usedConnectionNames.size();
	}

	if (!pool.m_unusedConnectionNames.empty())
	{
		connectionName = pool.m_unusedConnectionNames.dequeue();
	}
	else if (connectionCount < pool.m_maxConnectionCount)
	{
		connectionName = QString("Connection - %1").arg(connectionCount + 1);
	}
	else
	{
		return QSqlDatabase();
	}

	QSqlDatabase db = pool.createConnection(connectionName);

	if (db.isOpen())
	{
		pool.m_usedConnectionNames.enqueue(connectionName);
	}
	return db;
}

void SqlConnectionPool::closeConnection(QSqlDatabase connection)
{
	SqlConnectionPool & pool = SqlConnectionPool::getInstance();
	QString connectionName = connection.connectionName();

	if (pool.m_usedConnectionNames.contains(connectionName))
	{
		QMutexLocker locker(&m_mutex);
		pool.m_usedConnectionNames.removeOne(connectionName);
		pool.m_unusedConnectionNames.enqueue(connectionName);
		m_waitCondition.wakeOne();
	}
}

SqlConnectionPool& SqlConnectionPool::getInstance()
{
	static SqlConnectionPool instance;
	return instance;
}

QSqlDatabase SqlConnectionPool::createConnection(const QString& connectionName)
{
	if (QSqlDatabase::contains(connectionName))
	{
		QSqlDatabase db1 = QSqlDatabase::database(connectionName);

		if (m_testOnBorrow)
		{
			QSqlQuery query(m_testOnBorrowSql,db1);

			if (query.lastError().type() != QSqlError::NoError && !db1.open())
			{
				return QSqlDatabase();
			}
		}
		return db1;
	}

	QSqlDatabase db = QSqlDatabase::addDatabase(m_dataBaseType,connectionName);
	if (m_dataBaseType == "QSQLITE")
	{
		db.setDatabaseName(m_dataBaseName);
	}
	else
	{
		db.setDatabaseName(m_dataBaseName);
		db.setHostName(m_hostName);
		db.setUserName(m_userName);
		db.setPassword(m_password);

	}
	if (!db.open())
	{
		return QSqlDatabase();
	}
	return db;
}