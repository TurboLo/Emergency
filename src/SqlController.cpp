
#include "SqlController.h"
#include <QSqlQuery>
#include <qvariant.h>
#include <qDebug>
QMutex SqlController::m_mutex;
SqlController::SqlController(QObject *parent)
	:QObject(parent)
{

}

SqlController::~SqlController()
{

}
SqlController& SqlController::getInstance()
{
	QMutexLocker locker(&m_mutex);
	static SqlController instance;
	return instance;
}

void SqlController::insertIntoProvinceCityCountry(const ProvinceCityCountry& provinceInfo,const QString &tableName,const QSqlDatabase &db)
{
	QString sql;
	if (tableName == "Province")
	{
		sql = QString("insert into %4(Province_Code,Province_Description,Province_Country) \
			values ('%1','%2','%3')")
			.arg(provinceInfo.ProvinceCityCountryCode, 
				provinceInfo.ProvinceCityCountryDescription,
				provinceInfo.ProvinceCityCountryCountry, tableName);
	}
	else if (tableName == "City")
	{
		sql = QString("insert into %4(City_Code,City_Description,City_Province) \
			values ('%1','%2','%3')")
			.arg(provinceInfo.ProvinceCityCountryCode, 
				provinceInfo.ProvinceCityCountryDescription, 
				provinceInfo.ProvinceCityCountryCountry, tableName);
	}
	else if (tableName == "County")
	{
		sql = QString("insert into %4(County_Code,County_Description,County_Province) \
			values ('%1','%2','%3')")
			.arg(provinceInfo.ProvinceCityCountryCode, 
				provinceInfo.ProvinceCityCountryDescription, 
				provinceInfo.ProvinceCityCountryCountry, tableName);
	}
	
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << sql;
	}
}

void SqlController::selectNeedInsertTable(QMap<QString, QString>& needTableMap, QStringList& finishTableList, const QSqlDatabase& db)
{
	QString sql = QString("select * from ImportDataTable");
	QSqlQuery query(db);
	query.exec(sql);
	while (query.next())
	{
		if (query.value("ImportDataTable_Flag").toString() == "0")
		{
			needTableMap[query.value("ImportDataTable_Description").toString()] 
				= query.value("ImportDataTable_Code").toString();
		}
		else
		{
			finishTableList << query.value("ImportDataTable_Description").toString();
		}
	}
}

void SqlController::updateNeedInsertTable(const QString& tableName,const QSqlDatabase &db)
{
	QString sql = QString("update ImportDataTable set ImportDataTable_Flag = '1' \
	where ImportDataTable_Code = '%1' ")
		.arg(tableName);
	QSqlQuery query(db);
	query.exec(sql);
}

void SqlController::insertIntoSex(const Sex& sexInfo, const QSqlDatabase& db)
{
	QString sql = QString("insert into Sex(Sex_id,Sex_Description,Sex_Other) \
		values (%1,'%2','%3')")
		.arg(sexInfo.sexId, sexInfo.sexDescription, sexInfo.sexOther);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << sql;
	}
}

void SqlController::insertIntoHospital(const Hospital& hospitalInfo, const QSqlDatabase& db)
{
	QString sql = QString("insert into Hospital(Hospital_Code,Hospital_Description,Hospital_Other) \
		values ('%1','%2','%3')")
		.arg(hospitalInfo.hospitalCode, 
			hospitalInfo.hospitalDescription, 
			hospitalInfo.hospitalOther);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << sql;
	}
}

void SqlController::insertIntoMedicalStaff(const MedicalStaff& medicalStaff, const QSqlDatabase& db)
{
	QString sql = QString("insert into MedicalStaff \
		(MedicalStaff_Code,MedicalStaff_Name,MedicalStaff_Sex,MedicalStaff_Address,MedicalStaff_DoctorNo,MedicalStaff_InsuDoctorNo \
		,MedicalStaff_Type,MedicalStaff_Telephone,MedicalStaff_Anaesthetist,MedicalStaff_Surgeon,MedicalStaff_Loc,MedicalStaff_Ward,MedicalStaff_Title,MedicalStaff_Hospital) \
		values ('%1','%2',%3,'%4','%5','%6',%7,'%8',%9,%10,'%11','%12','%13','%14')")
		.arg(medicalStaff.medicalStaffCode)
		.arg(medicalStaff.medicalStaffName)
		.arg(medicalStaff.medicalStaffSex)
		.arg(medicalStaff.medicalStaffAddress)
		.arg(medicalStaff.medicalStaffDoctorNo)
		.arg(medicalStaff.medicalStaffInsuDoctorNo)
		.arg(medicalStaff.medicalStaffType)
		.arg(medicalStaff.medicalStaffTelephone)
		.arg(medicalStaff.medicalStaffAnaesthetist)
		.arg(medicalStaff.medicalStaffSurgeon)
		.arg(medicalStaff.medicalStaffLoc)
		.arg(medicalStaff.medicalStaffWard)
		.arg(medicalStaff.medicalStaffTitle)
		.arg(medicalStaff.medicalStaffHospital);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}


void SqlController::insertIntoDepartment(const Department& department, const QSqlDatabase& db)
{
	QString sql = QString("insert into Department \
		(Department_Code,Department_Description,Department_WardFlag,Department_Address,Department_Type \
		, Department_Group, Department_Hospital,Department_Valid,Department_StartTime,Department_EndTime) \
		values ('%1','%2',%3,'%4','%5','%6',%7,'%8',%9,%10')")
		.arg(department.departmentCode)
		.arg(department.departmentDescription)
		.arg(department.departmentWardFlag)
		.arg(department.departmentAddress)
		.arg(department.departmentType)
		.arg(department.departmentGroup)
		.arg(department.departmentHospital)
		.arg(department.departmentValid)
		.arg(department.departmentStartTime)
		.arg(department.departmentEndTime);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoDepartmentType(const DepartmentType& departmentType, const QSqlDatabase& db)
{
	QString sql = QString("insert into DepartmentType \
		(DepartmentType_Code,DepartmentType_Description) \
		values ('%1','%2')")
		.arg(departmentType.departmentTypeCode)
		.arg(departmentType.departmentTypeDescription);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoDoctorAndDepartment(const DoctorAndDepartment& doctorAndDepartment, const QSqlDatabase& db)
{
	QString sql = QString("insert into DoctorAndDepartment \
		(DoctorAndDepartment_DocCode,DoctorAndDepartment_DepCode) \
		values ('%1','%2')")
		.arg(doctorAndDepartment.doctorAndDepartmentDocCode)
		.arg(doctorAndDepartment.doctorAndDepartmentDepCode);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoDocAdviceCategories(const DocAdviceCategories& docAdviceCategories, const QSqlDatabase& db)
{
	QString sql = QString("insert into DocAdviceCategories \
		(DocAdviceCategories_Code,DocAdviceCategories_Desc) \
		values ('%1','%2')")
		.arg(docAdviceCategories.docAdviceCategoriesCode)
		.arg(docAdviceCategories.docAdviceCategoriesDesc);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoDocAdviceSubCat(const DocAdviceSubCat& docAdviceSubCat, const QSqlDatabase& db)
{
	QString sql = QString("insert into DocAdviceSubCat \
		(DocAdviceSubCat_Code,DocAdviceSubCat_Desc,DocAdviceSubCat_Upper) \
		values ('%1','%2','%3')")
		.arg(docAdviceSubCat.docAdviceSubCatCode)
		.arg(docAdviceSubCat.docAdviceSubCatDesc)
		.arg(docAdviceSubCat.docAdviceSubCatUpper);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoChargeCategories(const ChargeCategories& chargeCategories, const QSqlDatabase& db)
{
	QString sql = QString("insert into ChargeCategories \
		(Charge_Code,Charge_Desc) \
		values ('%1','%2')")
		.arg(chargeCategories.chargeCode)
		.arg(chargeCategories.chargeDesc);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoChargeSubCat(const ChargeSubCat & chargeSubCat, const QSqlDatabase& db)
{
	QString sql = QString("insert into ChargeSubCat \
		(ChargeSubCat_Code,ChargeSubCat_Desc,ChargeSubCat_Upper) \
		values ('%1','%2','%3')")
		.arg(chargeSubCat.chargeSubCatCode)
		.arg(chargeSubCat.chargeSubCatDesc)
		.arg(chargeSubCat.chargeSubCatUpper);
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoDoctorDevice(const DoctorDevice& doctorDevice, const QSqlDatabase& db)
{
	QString sql = QString("insert into DoctorDevice \
		(DoctorDevice_Code,DoctorDevice_Desc,DoctorDevice_SubCat£¬DoctorDevice_Abbrev \
		,DoctorDevice_Uom,DoctorDevice_AllowOrderWOStockCheck,DoctorDevice_Generic,DoctorDevice_AntimicrobialAgents \
		,DoctorDevice_AntimicrobialAgentsType,DoctorDevice_AntimicrobialAgentsDesc) \
		values ('%1','%2','%3','%4','%5',%6,'%7',%8,'%9','%10')")
		.arg(doctorDevice.doctorDeviceCode)
		.arg(doctorDevice.doctorDeviceDesc)
		.arg(doctorDevice.doctorDeviceSubCat)
		.arg(doctorDevice.doctorDeviceAbbrev)
		.arg(doctorDevice.doctorDeviceUom)
		.arg(doctorDevice.doctorDeviceAllowOrderWOStockCheck)
		.arg(doctorDevice.doctorDeviceGeneric)
		.arg(doctorDevice.doctorDeviceAntimicrobialAgents)
		.arg(doctorDevice.doctorDeviceAntimicrobialAgentsType)
		.arg(doctorDevice.doctorDeviceAntimicrobialAgentsDesc)
		;
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoChargingProjects(const ChargingProjects& chargingProjects, const QSqlDatabase& db)
{
	QString sql = QString("insert into ChargingProjects \
		(ChargingProjects_Code,ChargingProjects_Desc,ChargingProjects_SubCat£¬ChargingProjects_Abbrev \
		,ChargingProjects_Uom,ChargingProjects_Pric) \
		values ('%1','%2','%3','%4','%5','%6')")
		.arg(chargingProjects.chargingProjectsCode)
		.arg(chargingProjects.chargingProjectsDesc)
		.arg(chargingProjects.chargingProjectsSubCat)
		.arg(chargingProjects.chargingProjectsAbbrev)
		.arg(chargingProjects.chargingProjectsUom)
		.arg(chargingProjects.chargingProjectsPric)
		;
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoDoctorDeviceAndChargingProjects(const DoctorDeviceAndChargingProjects& doctorDeviceAndChargingProjects, const QSqlDatabase& db)
{
	QString sql = QString("insert into DoctorDeviceAndChargingProjects \
		(DoctorDevice_Code,DoctorDevice_Desc,ChargingProjects_Code£¬ChargingProjects_Desc,ChargingProjects_Num ) \
		values ('%1','%2','%3','%4','%5')")
		.arg(doctorDeviceAndChargingProjects.doctorDeviceCode)
		.arg(doctorDeviceAndChargingProjects.doctorDeviceDesc)
		.arg(doctorDeviceAndChargingProjects.chargingProjectsCode)
		.arg(doctorDeviceAndChargingProjects.chargingProjectsDesc)
		.arg(doctorDeviceAndChargingProjects.doctorDeviceNum)
		;
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoInsuranceProjects(const InsuranceProjects& insuranceProjects, const QSqlDatabase& db)
{
	QString sql = QString("insert into InsuranceProjects \
		(InsuranceProjects_Code,InsuranceProjects_Desc,InsuranceProjects_Type£¬InsuranceProjects_ChargeType,InsuranceProjects_Abbrev,InsuranceProjects_TJXM ) \
		values ('%1','%2','%3','%4','%5,'%6')")
		.arg(insuranceProjects.insuranceProjectsCode)
		.arg(insuranceProjects.insuranceProjectsDesc)
		.arg(insuranceProjects.insuranceProjectsType)
		.arg(insuranceProjects.insuranceProjectsChargeType)
		.arg(insuranceProjects.insuranceProjectsAbbrev)
		.arg(insuranceProjects.insuranceProjectsTJXM)
		;
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::insertIntoChargeProjectAndInsuranceProject(const ChargeProjectAndInsuranceProject& chargeProjectAndInsuranceProject, const QSqlDatabase& db)
{
	QString sql = QString("insert into ChargeProjectAndInsuranceProject \
		(ChargingProjects_Code,ChargingProjects_Desc,InsuranceProjects_Code£¬InsuranceProjects_Desc,InsuranceProjects_Type) \
		values ('%1','%2','%3','%4','%5,'%6')")
		.arg(chargeProjectAndInsuranceProject.chargingProjectsCode)
		.arg(chargeProjectAndInsuranceProject.chargingProjectsDesc)
		.arg(chargeProjectAndInsuranceProject.insuranceProjectsCode)
		.arg(chargeProjectAndInsuranceProject.insuranceProjectsDesc)
		.arg(chargeProjectAndInsuranceProject.insuranceProjectsType)
		;
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	if (!isOk)
	{
		qDebug() << query.lastError().databaseText();
		qDebug() << sql;
	}
}

void SqlController::selectFromSex(QList<Sex>& sexList, const QSqlDatabase& db)
{
	QString sql = QString("select * from Sex");
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	while (query.next())
	{
		Sex sex;
		sex.sexId = query.value("Sex_id").toString();
		sex.sexDescription = query.value("Sex_Description").toString();
		sexList.push_back(sex);
	}
}

void SqlController::selectFromCardType(QList<CardType>& cardTypeList, const QSqlDatabase& db)
{
	QString sql = QString("select * from CardType");
	QSqlQuery query(db);
	bool isOk = query.exec(sql);
	while (query.next())
	{
		CardType cardType;
		cardType.cardTypeCode = query.value("CardType_Code").toString();
		cardType.cardTypeDesc = query.value("CardType_Desc").toString();
		cardTypeList.push_back(cardType);
	}
}