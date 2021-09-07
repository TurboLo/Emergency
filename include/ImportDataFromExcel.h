/****************************************************************************
*						 ���ļ��е������������
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
	* @brief ������������ź�
	*/
	void sig_importThreadFinished();

private slots:

	/********************************************************************************
	* @brief ѡ���ļ���ť����ۺ���
	*/
	void on_pushButtonChooseFile_clicked();

	/********************************************************************************
	* @brief ���밴ť�������
	*/
	void on_pushButtonImport_clicked();

	/********************************************************************************
	* @brief ȡ����ť����ۺ���
	*/
	void on_pushButtonCancel_clicked();

	/********************************************************************************
	* @brief ������������̺߳���
	*/
	void dealImportThreadFinished();
		
private:
	void initUi();

	/********************************************************************************
	* @brief ʡ�����ر��뺯��
	*/
	void importProviceCityCounty(const QSqlDatabase& db);

	/********************************************************************************
	* @brief �Ա���뺯��
	*/
	void importSex(const QSqlDatabase& db);
	
	/********************************************************************************
	* @brief �Ա���뺯��
	*/
	void importHospital(const QSqlDatabase& db);

	/********************************************************************************
	* @brief ҽ����Ա���뺯��
	*/
	void importMedicalStaff(const QSqlDatabase& db);

	/********************************************************************************
	* @brief ���ұ��뺯��
	*/
	void importDepartment(const QSqlDatabase& db);

	/********************************************************************************
	* @brief �������ͱ��뺯��
	*/
	void importDepartmentType(const QSqlDatabase& db);

	/********************************************************************************
	* @brief ҽ�����Ҷ��ձ��뺯��
	*/
	void importDoctorAndDepartment(const QSqlDatabase& db);

	/********************************************************************************
	* @brief ҽ��������뺯��
	*/
	void importDocAdviceCategories(const QSqlDatabase& db);

	/********************************************************************************
	* @brief ҽ��������뺯��
	*/
	void importDocAdviceSubCat(const QSqlDatabase& db);

	/********************************************************************************
	* @brief �շѴ�����뺯��
	*/
	void importChargeCategories(const QSqlDatabase& db);

	/********************************************************************************
	* @brief �շ�������뺯��
	*/
	void importChargeSubCat(const QSqlDatabase& db);

	/********************************************************************************
	* @brief ҽ����Ŀ���뺯��
	*/
	void importDoctorDevice(const QSqlDatabase& db);

	/********************************************************************************
	* @brief �շ���Ŀ���뺯��
	*/
	void importChargingProjects(const QSqlDatabase& db);

	/********************************************************************************
	* @brief �շ���Ŀ���뺯��
	*/
	void importDoctorDeviceAndChargingProjects(const QSqlDatabase& db);

	/********************************************************************************
	* @brief ҽ����Ŀ���뺯��
	*/
	void importInsuranceProjects(const QSqlDatabase& db);

	/********************************************************************************
	* @brief �շ���Ŀ��ҽ����Ŀ���ձ��뺯��
	*/
	void importChargeProjectAndInsuranceProject(const QSqlDatabase& db);

	/********************************************************************************
	* @brief �������̺߳���
	*/
	void importThread(const QSqlDatabase& db);

private:
	Ui::ImportDataFromExcel ui{};

	QMap<QString, SignalFunction> m_funcMap{};

	SignalFunction GetFunc(const QString& key);

	std::thread* m_myThread{ nullptr };
};
#endif // !EMERGENCYSYSTEM_IMPORTDATAFROMEXCEL_H
