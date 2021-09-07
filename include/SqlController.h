/****************************************************************************
*							 ���ݿ⵼����
*****************************************************************************
*
*					 File Name : EMERGENCYSYSTEM_SQLCONTROLLER_H
*
*				  Project Name : SqlController
*
*					Programmer : Turbo
*
*				   Create Date : 2021-08-09
*
*				   Update Date :
*
*******************************************************************************/
#ifndef EMERGENCYSYSTEM_SQLCONTROLLER_H
#define EMERGENCYSYSTEM_SQLCONTROLLER_H

#include <QObject>
#include "SqlConnectionPool.h"
#include "Structure.h"
/*********************************************************************************
* this class is for control Db
*/
class SqlController : public QObject
{
	Q_OBJECT
public:
	/*****************************************************************************
	* @brief ���ݿ�����൥��
	*/
	static SqlController& getInstance();
	~SqlController();

	/*****************************************************************************
	* @brief ����ʡ������Ϣ�����ݿ�
	* @param provinceInfo ʡ������Ϣ  tableName ������
	*/
	void insertIntoProvinceCityCountry(const ProvinceCityCountry& provinceInfo, const QString& tableName, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ��ѯδ��ɵ�������ݿ�
	* @param needTableMap ����Ϣ��key���������� value �����ƣ�  finishTableList�����������ģ� �Ѿ�������ɵı�����
	*/
	void selectNeedInsertTable(QMap<QString, QString> & needTableMap, QStringList & finishTableList, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief �����Ѿ�����ı���Ϣ
	* @param tableName ������
	*/
	void updateNeedInsertTable(const QString& tableName, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief �����Ա���Ϣ
	* @param sexInfo �Ա���Ϣ
	*/
	void insertIntoSex(const Sex& sexInfo, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ����Ժ����Ϣ
	* @param hospitalInfo �Ա���Ϣ
	*/
	void insertIntoHospital(const Hospital& hospitalInfo, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ����ҽ����Ա��Ϣ
	* @param medicalStaff ҽ����Ա��Ϣ
	*/
	void insertIntoMedicalStaff(const MedicalStaff& medicalStaff, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ������ұ���Ϣ
	* @param department ������Ϣ
	*/
	void insertIntoDepartment(const Department& department, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ����������ͱ���Ϣ
	* @param departmentType ����������Ϣ
	*/
	void insertIntoDepartmentType(const DepartmentType& departmentType, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ����ҽ�����Ҷ��ձ���Ϣ
	* @param doctorAndDepartment ҽ�����Ҷ�����Ϣ
	*/
	void insertIntoDoctorAndDepartment(const DoctorAndDepartment& doctorAndDepartment, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ����ҽ���������Ϣ
	* @param docAdviceCategories ҽ���������Ϣ
	*/
	void insertIntoDocAdviceCategories(const DocAdviceCategories& docAdviceCategories, const QSqlDatabase& db);
	
	/*****************************************************************************
	* @brief ����ҽ���������Ϣ
	* @param docAdviceSubCat ҽ���������Ϣ
	*/
	void insertIntoDocAdviceSubCat(const DocAdviceSubCat& docAdviceSubCat, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief �����շ���������Ϣ
	* @param chargeCategories �շ���������Ϣ
	*/
	void insertIntoChargeCategories(const ChargeCategories& chargeCategories, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief �����շ����������Ϣ
	* @param chargeSubCat �շ����������Ϣ
	*/
	void insertIntoChargeSubCat(const ChargeSubCat& chargeSubCat, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ����ҽ�������Ϣ
	* @param doctorDevice ҽ�������Ϣ
	*/
	void insertIntoDoctorDevice(const DoctorDevice& doctorDevice, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief �����շ���Ŀ����Ϣ
	* @param chargingProjects �շ���Ŀ����Ϣ
	*/
	void insertIntoChargingProjects(const ChargingProjects& chargingProjects, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief �����շ���Ŀ����Ϣ
	* @param chargingProjects �շ���Ŀ����Ϣ
	*/
	void insertIntoDoctorDeviceAndChargingProjects(const DoctorDeviceAndChargingProjects& doctorDeviceAndChargingProjects, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ����ҽ����Ŀ����Ϣ
	* @param chargingProjects ҽ����Ŀ����Ϣ
	*/
	void insertIntoInsuranceProjects(const InsuranceProjects& insuranceProjects, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief �����շ���Ŀ��ҽ����Ŀ���ձ���Ϣ
	* @param chargingProject �շ���Ŀ��ҽ����Ŀ���ձ���Ϣ
	*/
	void insertIntoChargeProjectAndInsuranceProject(const ChargeProjectAndInsuranceProject& chargeProjectAndInsuranceProject, const QSqlDatabase& db);

public:
	/*****************************************************************************
	* @brief ��ѯ�����Ա���Ϣ
	* @param sexInfo �Ա���Ϣ
	*/
	void selectFromSex(QList<Sex>& sexList, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief ��ѯ��������Ϣ
	* @param sexInfo �Ա���Ϣ
	*/
	void selectFromCardType(QList<CardType>& cardTypeList, const QSqlDatabase& db);

private:
	explicit SqlController(QObject* parent = nullptr);
private:
	// ���ݿ����
	QSqlDatabase m_db;

	static QMutex m_mutex;
};


#endif // EMERGENCYSYSTEM_SQLCONTROLLER_H
