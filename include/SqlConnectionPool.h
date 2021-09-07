/****************************************************************************
*							 ���ݿ����ӳ���
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
	* @brief �ر��������ݿ�����
	*/
	static void release();  

	/***************************************************************************
	* @brief ��ȡ���ݿ�����
	*/
	static QSqlDatabase openConnection();
	
	/***************************************************************************
	* @brief �ر����ݿ�����
	*/
	static void closeConnection(QSqlDatabase connection);
	
	/***************************************************************************
	* @brief  ���ݿ����ӳض��ⵥ��
	*/
	static SqlConnectionPool& getInstance();

	~SqlConnectionPool();

private:
	SqlConnectionPool();
	
	/***************************************************************************
	* @brief  �������ݿ�����
	*/
	QSqlDatabase createConnection(const QString& connectionName);

private:

	// �Ѿ�ʹ�õ����ݿ���������
	QQueue<QString> m_usedConnectionNames;

	// δʹ�õ����ݿ���������
	QQueue<QString> m_unusedConnectionNames;

	// ���ݿ�������Ϣ
	QString m_hostName;
	QString m_dataBaseName;
	QString m_userName;
	QString m_password;
	QString m_dataBaseType;

	// ȡ������ʱ����֤�����Ƿ���Ч
	bool m_testOnBorrow;

	// ���Է������ݿ��sql
	QString m_testOnBorrowSql;

	// ���Ի�ȡ���ĵȴ�ʱ��
	int m_maxWaitTime;

	// ���Ի�ȡ���ӵȴ����¼����
	int m_waitInterval;

	// �����������
	int m_maxConnectionCount;

	// ������
	static QMutex m_mutex;
	
	static QWaitCondition m_waitCondition;

	QString m_settingPath;
};


#endif // !EMERGENCYSYSTEM_SQLCONNECTIONPOOL_H
