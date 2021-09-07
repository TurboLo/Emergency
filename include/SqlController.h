/****************************************************************************
*							 数据库导入类
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
	* @brief 数据库操作类单例
	*/
	static SqlController& getInstance();
	~SqlController();

	/*****************************************************************************
	* @brief 导入省市县信息到数据库
	* @param provinceInfo 省市县信息  tableName 表名称
	*/
	void insertIntoProvinceCityCountry(const ProvinceCityCountry& provinceInfo, const QString& tableName, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 查询未完成导入的数据库
	* @param needTableMap 表信息（key表名称中文 value 表名称）  finishTableList（表名称中文） 已经导入完成的表名称
	*/
	void selectNeedInsertTable(QMap<QString, QString> & needTableMap, QStringList & finishTableList, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 更新已经导入的表信息
	* @param tableName 表名称
	*/
	void updateNeedInsertTable(const QString& tableName, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入性别信息
	* @param sexInfo 性别信息
	*/
	void insertIntoSex(const Sex& sexInfo, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入院区信息
	* @param hospitalInfo 性别信息
	*/
	void insertIntoHospital(const Hospital& hospitalInfo, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入医护人员信息
	* @param medicalStaff 医护人员信息
	*/
	void insertIntoMedicalStaff(const MedicalStaff& medicalStaff, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入科室表信息
	* @param department 科室信息
	*/
	void insertIntoDepartment(const Department& department, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入科室类型表信息
	* @param departmentType 科室类型信息
	*/
	void insertIntoDepartmentType(const DepartmentType& departmentType, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入医生科室对照表信息
	* @param doctorAndDepartment 医生科室对照信息
	*/
	void insertIntoDoctorAndDepartment(const DoctorAndDepartment& doctorAndDepartment, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入医嘱大类表信息
	* @param docAdviceCategories 医嘱大类表信息
	*/
	void insertIntoDocAdviceCategories(const DocAdviceCategories& docAdviceCategories, const QSqlDatabase& db);
	
	/*****************************************************************************
	* @brief 导入医嘱子类表信息
	* @param docAdviceSubCat 医嘱子类表信息
	*/
	void insertIntoDocAdviceSubCat(const DocAdviceSubCat& docAdviceSubCat, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入收费项大类表信息
	* @param chargeCategories 收费项大类表信息
	*/
	void insertIntoChargeCategories(const ChargeCategories& chargeCategories, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入收费项子类表信息
	* @param chargeSubCat 收费项子类表信息
	*/
	void insertIntoChargeSubCat(const ChargeSubCat& chargeSubCat, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入医嘱项表信息
	* @param doctorDevice 医嘱项表信息
	*/
	void insertIntoDoctorDevice(const DoctorDevice& doctorDevice, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入收费项目表信息
	* @param chargingProjects 收费项目表信息
	*/
	void insertIntoChargingProjects(const ChargingProjects& chargingProjects, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入收费项目表信息
	* @param chargingProjects 收费项目表信息
	*/
	void insertIntoDoctorDeviceAndChargingProjects(const DoctorDeviceAndChargingProjects& doctorDeviceAndChargingProjects, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入医保项目表信息
	* @param chargingProjects 医保项目表信息
	*/
	void insertIntoInsuranceProjects(const InsuranceProjects& insuranceProjects, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 导入收费项目和医保项目对照表信息
	* @param chargingProject 收费项目和医保项目对照表信息
	*/
	void insertIntoChargeProjectAndInsuranceProject(const ChargeProjectAndInsuranceProject& chargeProjectAndInsuranceProject, const QSqlDatabase& db);

public:
	/*****************************************************************************
	* @brief 查询患者性别信息
	* @param sexInfo 性别信息
	*/
	void selectFromSex(QList<Sex>& sexList, const QSqlDatabase& db);

	/*****************************************************************************
	* @brief 查询卡类型信息
	* @param sexInfo 性别信息
	*/
	void selectFromCardType(QList<CardType>& cardTypeList, const QSqlDatabase& db);

private:
	explicit SqlController(QObject* parent = nullptr);
private:
	// 数据库对象
	QSqlDatabase m_db;

	static QMutex m_mutex;
};


#endif // EMERGENCYSYSTEM_SQLCONTROLLER_H
