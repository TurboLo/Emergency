#include "ImportDataFromExcel.h"

ImportDataFromExcel::ImportDataFromExcel(QWidget* parent)
	:QMainWindow(parent)
{
	ui.setupUi(this);
	initUi();
	m_funcMap = {
		{"Province",&ImportDataFromExcel::importProviceCityCounty}
		,{"City",&ImportDataFromExcel::importProviceCityCounty}
		,{"County",&ImportDataFromExcel::importProviceCityCounty}
		,{"Sex",&ImportDataFromExcel::importSex}
		,{"Hospital",&ImportDataFromExcel::importHospital}
		,{"MedicalStaff",&ImportDataFromExcel::importMedicalStaff}
		,{"Department",&ImportDataFromExcel::importDepartment}
		,{"DepartmentType",&ImportDataFromExcel::importDepartmentType}
		,{"DoctorAndDepartment",&ImportDataFromExcel::importDoctorAndDepartment}
		,{"DocAdviceCategories",&ImportDataFromExcel::importDocAdviceCategories}
		,{"DocAdviceSubCat",&ImportDataFromExcel::importDocAdviceSubCat}
		,{"ChargeCategories",&ImportDataFromExcel::importChargeCategories}
		,{"ChargeSubCat",&ImportDataFromExcel::importChargeSubCat}
		,{"DoctorDevice",&ImportDataFromExcel::importDoctorDevice}
		,{"ChargingProjects",&ImportDataFromExcel::importChargingProjects}
		,{"DoctorDeviceAndChargingProjects",&ImportDataFromExcel::importDoctorDeviceAndChargingProjects}
		,{"InsuranceProjects",&ImportDataFromExcel::importInsuranceProjects}
		,{"ChargeProjectAndInsuranceProject",&ImportDataFromExcel::importChargeProjectAndInsuranceProject}
	};

	connect(this, &ImportDataFromExcel::sig_importThreadFinished, this, &ImportDataFromExcel::dealImportThreadFinished);
}

ImportDataFromExcel::SignalFunction ImportDataFromExcel::GetFunc(const QString &key)
{
	return m_funcMap[key];
}

void ImportDataFromExcel::on_pushButtonImport_clicked()
{
	if (m_myThread != nullptr)
	{
		QMessageBox::warning(this, "wait", QString::fromLocal8Bit("正在导入数据，请稍等！"));
		return;
	}
	QSqlDatabase db = SqlConnectionPool::openConnection();
	m_myThread = new std::thread(&ImportDataFromExcel::importThread, this , db);
}

void ImportDataFromExcel::importThread(const QSqlDatabase &db)
{
	QString str = ui.comboBoxTable->currentData().toString();
	auto func = GetFunc(str);
	if (func != nullptr)
	{
		(this->*func)(db);
	}
	SqlController::getInstance().updateNeedInsertTable(str,db);
	SqlConnectionPool::closeConnection(db);
	emit sig_importThreadFinished();
}

void ImportDataFromExcel::dealImportThreadFinished()
{
	m_myThread->join();
	delete m_myThread;
	m_myThread = nullptr;
	QMessageBox::information(this, "Tip", QString::fromLocal8Bit("导入已经完成，请查看导入日志"));
	initUi();
}

void ImportDataFromExcel::on_pushButtonCancel_clicked()
{
	hide();
}

void ImportDataFromExcel::initUi()
{
	ui.comboBoxTable->clear();
	QMap<QString, QString> needTableMap;
	QStringList finishTableList;
	QSqlDatabase db = SqlConnectionPool::openConnection();
	SqlController::getInstance().selectNeedInsertTable(needTableMap, finishTableList,db);
	SqlConnectionPool::closeConnection(db);
	auto it = needTableMap.constBegin();
	while (it != needTableMap.constEnd())
	{
		ui.comboBoxTable->addItem(it.key(), it.value());
		it++;
	}
	QString finishTableStr;
	for (const auto& finishTable : finishTableList)
	{
		finishTableStr = finishTableStr + finishTable + " ";
		ui.labelFinishedTable->setText(finishTableStr);
	}
}

ImportDataFromExcel::~ImportDataFromExcel()
{

}

void ImportDataFromExcel::on_pushButtonChooseFile_clicked()
{
	QString filePath = QFileDialog::getOpenFileName(this, "openFile", "./", "*.csv");
	if (filePath.isEmpty())
	{
		return;
	}
	ui.lineEditFilePath->setText(filePath);
}

void ImportDataFromExcel::importProviceCityCounty(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		ProvinceCityCountry provinceCityCountry;
		QStringList list = stream.readLine().split(",");
		provinceCityCountry.ProvinceCityCountryCode = list.at(0);
		provinceCityCountry.ProvinceCityCountryDescription = list.at(1);
		provinceCityCountry.ProvinceCityCountryCountry = list.at(2);
		SqlController::getInstance().insertIntoProvinceCityCountry(provinceCityCountry, tableName ,db);
	}
	file.close();
}



void ImportDataFromExcel::importSex(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		Sex sex;
		QStringList list = stream.readLine().split(",");
		sex.sexId = list.at(0);
		sex.sexDescription = list.at(1);
		SqlController::getInstance().insertIntoSex(sex, db);
	}
	file.close();
}

void ImportDataFromExcel::importHospital(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		Hospital hospital;
		QStringList list = stream.readLine().split(",");
		hospital.hospitalCode = list.at(0);
		hospital.hospitalDescription = list.at(1);
		hospital.hospitalOther = list.at(2);
		SqlController::getInstance().insertIntoHospital(hospital, db);
	}
	file.close();
}

void ImportDataFromExcel::importMedicalStaff(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		MedicalStaff medicalStaff;
		QStringList list = stream.readLine().split(",");
		medicalStaff.medicalStaffCode = list.at(0);
		medicalStaff.medicalStaffName = list.at(1);
		medicalStaff.medicalStaffSex = (list.at(2).trimmed()==QString::fromLocal8Bit("男") ? 1:2);
		medicalStaff.medicalStaffAddress = list.at(3);
		medicalStaff.medicalStaffDoctorNo = list.at(4);
		medicalStaff.medicalStaffInsuDoctorNo = list.at(5);
		medicalStaff.medicalStaffType = list.at(6);
		medicalStaff.medicalStaffTelephone = list.at(7);
		medicalStaff.medicalStaffAnaesthetist = list.at(8);
		medicalStaff.medicalStaffSurgeon = list.at(9);
		medicalStaff.medicalStaffLoc = list.at(10);
		medicalStaff.medicalStaffWard = list.at(11);
		medicalStaff.medicalStaffTitle = list.at(12);
		medicalStaff.medicalStaffHospital = list.at(13);
		SqlController::getInstance().insertIntoMedicalStaff(medicalStaff, db);
	}
	file.close();
}


void ImportDataFromExcel::importDepartment(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		Department department;
		QStringList list = stream.readLine().split(",");
		department.departmentCode = list.at(0);
		department.departmentDescription = list.at(1);
		department.departmentWardFlag = list.at(2);
		department.departmentAddress = list.at(3);
		department.departmentType = list.at(4);
		department.departmentGroup = list.at(5);
		department.departmentHospital = list.at(6);
		department.departmentValid = list.at(7);
		department.departmentStartTime = list.at(8);
		department.departmentEndTime = list.at(9);
		SqlController::getInstance().insertIntoDepartment(department, db);
	}
	file.close();
}



void ImportDataFromExcel::importDepartmentType(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		DepartmentType departmentType;
		QStringList list = stream.readLine().split(",");
		departmentType.departmentTypeCode = list.at(0);
		departmentType.departmentTypeDescription = list.at(1);
		SqlController::getInstance().insertIntoDepartmentType(departmentType, db);
	}
	file.close();
}

void ImportDataFromExcel::importDoctorAndDepartment(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		DoctorAndDepartment doctorAndDepartment;
		QStringList list = stream.readLine().split(",");
		doctorAndDepartment.doctorAndDepartmentDocCode = list.at(0);
		doctorAndDepartment.doctorAndDepartmentDepCode = list.at(1);
		SqlController::getInstance().insertIntoDoctorAndDepartment(doctorAndDepartment, db);
	}
	file.close();
}

void ImportDataFromExcel::importDocAdviceCategories(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		DocAdviceCategories docAdviceCategories;
		QStringList list = stream.readLine().split(",");
		docAdviceCategories.docAdviceCategoriesCode = list.at(0);
		docAdviceCategories.docAdviceCategoriesDesc = list.at(1);
		SqlController::getInstance().insertIntoDocAdviceCategories(docAdviceCategories, db);
	}
	file.close();
}

void ImportDataFromExcel::importDocAdviceSubCat(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		DocAdviceSubCat docAdviceSubCat;
		QStringList list = stream.readLine().split(",");
		docAdviceSubCat.docAdviceSubCatCode = list.at(0);
		docAdviceSubCat.docAdviceSubCatDesc = list.at(1);
		docAdviceSubCat.docAdviceSubCatUpper = list.at(2);
		SqlController::getInstance().insertIntoDocAdviceSubCat(docAdviceSubCat, db);
	}
	file.close();
}


void ImportDataFromExcel::importChargeCategories(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		ChargeCategories chargeCategories;
		QStringList list = stream.readLine().split(",");
		chargeCategories.chargeCode = list.at(0);
		chargeCategories.chargeDesc = list.at(1);
		SqlController::getInstance().insertIntoChargeCategories(chargeCategories, db);
	}
	file.close();
}

void ImportDataFromExcel::importChargeSubCat(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		ChargeSubCat chargeSubCat;
		QStringList list = stream.readLine().split(",");
		chargeSubCat.chargeSubCatCode = list.at(0);
		chargeSubCat.chargeSubCatDesc = list.at(1);
		chargeSubCat.chargeSubCatUpper = list.at(2);
		SqlController::getInstance().insertIntoChargeSubCat(chargeSubCat, db);
	}
	file.close();
}

void ImportDataFromExcel::importDoctorDevice(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		DoctorDevice doctorDevice;
		QStringList list = stream.readLine().split(",");
		doctorDevice.doctorDeviceCode = list.at(0);
		doctorDevice.doctorDeviceDesc = list.at(1);
		doctorDevice.doctorDeviceSubCat = list.at(2);
		doctorDevice.doctorDeviceAbbrev = list.at(3);
		doctorDevice.doctorDeviceUom = list.at(4);
		doctorDevice.doctorDeviceAllowOrderWOStockCheck = list.at(5);
		doctorDevice.doctorDeviceGeneric = list.at(6);
		doctorDevice.doctorDeviceAntimicrobialAgents = list.at(7);
		doctorDevice.doctorDeviceAntimicrobialAgentsType = list.at(8);
		doctorDevice.doctorDeviceAntimicrobialAgentsDesc = list.at(9);
		SqlController::getInstance().insertIntoDoctorDevice(doctorDevice, db);
	}
	file.close();
}

void ImportDataFromExcel::importChargingProjects(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		ChargingProjects chargingProjects;
		QStringList list = stream.readLine().split(",");
		chargingProjects.chargingProjectsCode = list.at(0);
		chargingProjects.chargingProjectsDesc = list.at(1);
		chargingProjects.chargingProjectsSubCat = list.at(2);
		chargingProjects.chargingProjectsAbbrev = list.at(3);
		chargingProjects.chargingProjectsUom = list.at(4);
		chargingProjects.chargingProjectsPric = list.at(5);
		SqlController::getInstance().insertIntoChargingProjects(chargingProjects, db);
	}
	file.close();
}

void ImportDataFromExcel::importDoctorDeviceAndChargingProjects(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		DoctorDeviceAndChargingProjects doctorDeviceAndChargingProjects;
		QStringList list = stream.readLine().split(",");
		doctorDeviceAndChargingProjects.doctorDeviceCode = list.at(0);
		doctorDeviceAndChargingProjects.doctorDeviceDesc = list.at(1);
		doctorDeviceAndChargingProjects.chargingProjectsCode = list.at(2);
		doctorDeviceAndChargingProjects.chargingProjectsDesc = list.at(3);
		doctorDeviceAndChargingProjects.doctorDeviceNum = list.at(4);
		SqlController::getInstance().insertIntoDoctorDeviceAndChargingProjects(doctorDeviceAndChargingProjects, db);
	}
	file.close();
}

void ImportDataFromExcel::importInsuranceProjects(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		InsuranceProjects insuranceProjects;
		QStringList list = stream.readLine().split(",");
		insuranceProjects.insuranceProjectsCode = list.at(0);
		insuranceProjects.insuranceProjectsDesc = list.at(1);
		insuranceProjects.insuranceProjectsType = list.at(2);
		insuranceProjects.insuranceProjectsChargeType = list.at(3);
		insuranceProjects.insuranceProjectsAbbrev = list.at(4);
		insuranceProjects.insuranceProjectsTJXM = list.at(5);
		SqlController::getInstance().insertIntoInsuranceProjects(insuranceProjects, db);
	}
	file.close();
}

void ImportDataFromExcel::importChargeProjectAndInsuranceProject(const QSqlDatabase& db)
{
	QString tableName = ui.comboBoxTable->currentData().toString();
	QFile file(ui.lineEditFilePath->text());
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	stream.readLine();
	while (!stream.atEnd())
	{
		ChargeProjectAndInsuranceProject chargeProjectAndInsuranceProject;
		QStringList list = stream.readLine().split(",");
		chargeProjectAndInsuranceProject.chargingProjectsCode = list.at(0);
		chargeProjectAndInsuranceProject.chargingProjectsDesc = list.at(1);
		chargeProjectAndInsuranceProject.insuranceProjectsCode = list.at(2);
		chargeProjectAndInsuranceProject.insuranceProjectsDesc = list.at(3);
		chargeProjectAndInsuranceProject.insuranceProjectsType = list.at(4);
		SqlController::getInstance().insertIntoChargeProjectAndInsuranceProject(chargeProjectAndInsuranceProject, db);
	}
	file.close();
}