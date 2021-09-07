/****************************************************************************
*							 数据库连接池类
*****************************************************************************
* 
*					 File Name : EMERGENCYSYSTEM_SQLCONNECTIONPOOL_H
* 
*				  Project Name : SqlConnectionPool
* 
*					Programmer : Turbo
* 
*				   Create Date : 2021-08-09
* 
*				   Update Date : 
* 
*******************************************************************************/

#ifndef EMERGENCYSYSTEM_SQLCONNECTIONPOOL_H
#define EMERGENCYSYSTEM_SQLCONNECTIONPOOL_H
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>
/*******************************************************************************
* this class if for database connection
*/
class SqlConnectionPool
{
public:
	/***************************************************************************
	* @brief 关闭所有数据库连接
	*/
	static void release();  

	/***************************************************************************
	* @brief 获取数据库连接
	*/
	static QSqlDatabase openConnection();
	
	/***************************************************************************
	* @brief 关闭数据库连接
	*/
	static void closeConnection(QSqlDatabase connection);
	
	/***************************************************************************
	* @brief  数据库连接池对外单例
	*/
	static SqlConnectionPool& getInstance();

	~SqlConnectionPool();

private:
	SqlConnectionPool();
	
	/***************************************************************************
	* @brief  创建数据库连接
	*/
	QSqlDatabase createConnection(const QString& connectionName);

private:

	// 已经使用的数据库连接名称
	QQueue<QString> m_usedConnectionNames;

	// 未使用的数据库连接名称
	QQueue<QString> m_unusedConnectionNames;

	// 数据库连接信息
	QString m_hostName;
	QString m_dataBaseName;
	QString m_userName;
	QString m_password;
	QString m_dataBaseType;

	// 取得连接时候验证连接是否有效
	bool m_testOnBorrow;

	// 测试访问数据库的sql
	QString m_testOnBorrowSql;

	// 尝试获取最大的等待时间
	int m_maxWaitTime;

	// 尝试获取连接等待的事件间隔
	int m_waitInterval;

	// 最大连接数量
	int m_maxConnectionCount;

	// 队列锁
	static QMutex m_mutex;
	
	static QWaitCondition m_waitCondition;

	QString m_settingPath;
};


#endif // !EMERGENCYSYSTEM_SQLCONNECTIONPOOL_H
