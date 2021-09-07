/****************************************************************************
*						 从文件中导入基础数据类
*****************************************************************************
*
*					 File Name : EMERGENCYSYSTEM_IMPORTDATAFROMEXCEL_H
*
*				  Project Name : ImportDataFromExcel
*
*					Programmer : Turbo
*
*				   Create Date : 2021-08-09
*
*				   Update Date :
*
*******************************************************************************/

#ifndef EMERGENCYSYSTEM_IMPORTDATAFROMEXCEL_H
#define EMERGENCYSYSTEM_IMPORTDATAFROMEXCEL_H
#include <QMainWindow>
#include "ui_ImportDataFromExcel.h"
#include <qfiledialog.h>
#include <ActiveQt/qaxobject.h>
#include <QStandardPaths>
#include <QMessageBox>
#include <QTextStream>
#include "SqlController.h"
#include <thread>
QT_BEGIN_NAMESPACE
namespace Ui { class ImportDataFromExcel; }
QT_END_NAMESPACE

/********************************************************************************
* this class is for import data from excel files
*/
class ImportDataFromExcel : public QMainWindow
{
	typedef void (ImportDataFromExcel::*SignalFunction)(const QSqlDatabase& db);
	Q_OBJECT
public:
	explicit ImportDataFromExcel(QWidget* parent = nullptr);
	~ImportDataFromExcel() override;
signals:

	/********************************************************************************
	* @brief 导入数据完成信号
	*/
	void sig_importThreadFinished();

private slots:

	/********************************************************************************
	* @brief 选择文件按钮点击槽函数
	*/
	void on_pushButtonChooseFile_clicked();

	/********************************************************************************
	* @brief 导入按钮点击函数
	*/
	void on_pushButtonImport_clicked();

	/********************************************************************************
	* @brief 取消按钮点击槽函数
	*/
	void on_pushButtonCancel_clicked();

	/********************************************************************************
	* @brief 导入数据完成线程函数
	*/
	void dealImportThreadFinished();
		
private:
	void initUi();

	/********************************************************************************
	* @brief 省市区县表导入函数
	*/
	void importProviceCityCounty(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 性别表导入函数
	*/
	void importSex(const QSqlDatabase& db);
	
	/********************************************************************************
	* @brief 性别表导入函数
	*/
	void importHospital(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 医护人员表导入函数
	*/
	void importMedicalStaff(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 科室表导入函数
	*/
	void importDepartment(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 科室类型表导入函数
	*/
	void importDepartmentType(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 医生科室对照表导入函数
	*/
	void importDoctorAndDepartment(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 医嘱大类表导入函数
	*/
	void importDocAdviceCategories(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 医嘱子类表导入函数
	*/
	void importDocAdviceSubCat(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 收费大类表导入函数
	*/
	void importChargeCategories(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 收费子类表导入函数
	*/
	void importChargeSubCat(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 医嘱项目表导入函数
	*/
	void importDoctorDevice(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 收费项目表导入函数
	*/
	void importChargingProjects(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 收费项目表导入函数
	*/
	void importDoctorDeviceAndChargingProjects(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 医保项目表导入函数
	*/
	void importInsuranceProjects(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 收费项目和医保项目对照表导入函数
	*/
	void importChargeProjectAndInsuranceProject(const QSqlDatabase& db);

	/********************************************************************************
	* @brief 导数据线程函数
	*/
	void importThread(const QSqlDatabase& db);

private:
	Ui::ImportDataFromExcel ui{};

	QMap<QString, SignalFunction> m_funcMap{};

	SignalFunction GetFunc(const QString& key);

	std::thread* m_myThread{ nullptr };
};
#endif // !EMERGENCYSYSTEM_IMPORTDATAFROMEXCEL_H
