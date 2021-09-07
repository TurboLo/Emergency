/****************************************************************************
*							 结构体存储
*****************************************************************************
*
*					 File Name : EMERGENCYSYSTEM_STRUCTURE_H
*
*				  Project Name : 
*
*					Programmer : Turbo
*
*				   Create Date : 2021-08-10
*
*				   Update Date :
*
*******************************************************************************/
#ifndef EMERGENCYSYSTEM_STRUCTURE_H
#define EMERGENCYSYSTEM_STRUCTURE_H

#include <QString>
/*****************************************************************************
* this struct is for Patient's information
*/
struct Person
{
	Person() = default;
	Person(const Person& other)
	{

	}
	QString patientNo{};

};

/*****************************************************************************
* this struct is for (Province and City) Country's information
*/
struct ProvinceCityCountry
{
	ProvinceCityCountry() = default;
	ProvinceCityCountry(const ProvinceCityCountry& other)
	{
		ProvinceCityCountryCode = other.ProvinceCityCountryCode;
		ProvinceCityCountryDescription = other.ProvinceCityCountryDescription;
		ProvinceCityCountryCountry = other.ProvinceCityCountryCountry;
	}
	// 编码
	QString ProvinceCityCountryCode{};
	// 描述
	QString ProvinceCityCountryDescription{};
	// 上层编码
	QString ProvinceCityCountryCountry{};
};

/*****************************************************************************
* this struct is for Sex
*/
struct Sex
{
	Sex() = default;
	Sex(const Sex& other)
	{
		sexId = other.sexId;
		sexDescription = other.sexDescription;
		sexOther = other.sexOther;
	}
	// 编码
	QString sexId{};
	// 描述
	QString sexDescription{};
	// 预留字段
	QString sexOther{};
};

/*****************************************************************************
* this struct is for Hospital
*/
struct Hospital
{
	Hospital() = default;
	Hospital(const Hospital& other)
	{
		hospitalCode = other.hospitalCode;
		hospitalDescription = other.hospitalDescription;
		hospitalOther = other.hospitalOther;
	}
	// 编码
	QString hospitalCode{};
	// 描述
	QString hospitalDescription{};
	// 预留字段
	QString hospitalOther{};
};

/*****************************************************************************
* this struct is for MedicalStaff
*/
struct MedicalStaff
{
	MedicalStaff() = default;
	MedicalStaff(const MedicalStaff& other)
	{
		medicalStaffCode = other.medicalStaffCode;
		medicalStaffName = other.medicalStaffName;
		medicalStaffSex = other.medicalStaffSex;
		medicalStaffAddress = other.medicalStaffAddress;
		medicalStaffDoctorNo = other.medicalStaffDoctorNo;
		medicalStaffInsuDoctorNo = other.medicalStaffInsuDoctorNo;
		medicalStaffType = other.medicalStaffType;
		medicalStaffTelephone = other.medicalStaffTelephone;
		medicalStaffAnaesthetist = other.medicalStaffAnaesthetist;
		medicalStaffSurgeon = other.medicalStaffSurgeon;
		medicalStaffLoc = other.medicalStaffLoc;
		medicalStaffWard = other.medicalStaffWard;
		medicalStaffTitle = other.medicalStaffTitle;
		medicalStaffHospital = other.medicalStaffHospital;
	}
	// 医护人员工号
	QString medicalStaffCode{};
	// 医护人员姓名
	QString medicalStaffName{};
	// 医护人员性别
	int medicalStaffSex{};
	// 医护人员地址
	QString medicalStaffAddress{};
	// 医护人员资格证号
	QString medicalStaffDoctorNo{};
	// 医护人员医保人员编码
	QString medicalStaffInsuDoctorNo{};
	// 医护人员类型
	QString medicalStaffType{};
	// 医护人员电话
	QString medicalStaffTelephone{};
	// 医护人员是否麻醉医生
	QString medicalStaffAnaesthetist{};
	// 医护人员是否外科医生
	QString medicalStaffSurgeon{};
	// 医护人员所属科室
	QString medicalStaffLoc{};
	// 医护人员所属病区
	QString medicalStaffWard{};
	// 医护人员职称
	QString medicalStaffTitle{};
	// 医护人员所属院区
	QString medicalStaffHospital{};
};

/*****************************************************************************
* 科室表结构体
*/
struct Department
{
	Department() = default;
	Department(const Department& other)
	{
		departmentCode = other.departmentCode;
		departmentDescription = other.departmentDescription;
		departmentWardFlag = other.departmentWardFlag;
		departmentAddress = other.departmentAddress;
		departmentType = other.departmentType;
		departmentGroup = other.departmentGroup;
		departmentHospital = other.departmentHospital;
		departmentValid = other.departmentValid;
		departmentStartTime = other.departmentStartTime;
		departmentEndTime = other.departmentEndTime;
	}
	// 科室编码
	QString departmentCode{};
	// 科室描述
	QString departmentDescription{};
	// 是否为病区
	QString	departmentWardFlag{};
	// 科室地址
	QString	departmentAddress{};
	// 科室类型
	QString	departmentType{};
	// 科室所属组
	QString	departmentGroup{};
	// 所属院区
	QString	departmentHospital{};
	// 科室是否有效
	QString	departmentValid{};
	// 科室设立时间
	QString	departmentStartTime{};
	// 科室终止时间
	QString	departmentEndTime{};
};

/*****************************************************************************
* 科室类型结构体
*/
struct DepartmentType
{
	DepartmentType() = default;
	DepartmentType(const DepartmentType& other)
	{
		departmentTypeCode = other.departmentTypeCode;
		departmentTypeDescription = other.departmentTypeDescription;
	}
	// 类型编码
	QString departmentTypeCode;
	// 类型描述
	QString	departmentTypeDescription;
};

/*****************************************************************************
* 医生科室关联结构体
*/
struct DoctorAndDepartment
{
	DoctorAndDepartment() = default;
	DoctorAndDepartment(const DoctorAndDepartment& other)
	{
		doctorAndDepartmentDocCode = other.doctorAndDepartmentDocCode;
		doctorAndDepartmentDepCode = other.doctorAndDepartmentDepCode;
	}
	// 医生工号
	QString doctorAndDepartmentDocCode;
	// 科室编码
	QString	doctorAndDepartmentDepCode;
};

/*****************************************************************************
* 医嘱大类结构体
*/
struct DocAdviceCategories
{
	DocAdviceCategories() = default;
	DocAdviceCategories(const DocAdviceCategories& other)
	{
		docAdviceCategoriesCode = other.docAdviceCategoriesCode;
		docAdviceCategoriesDesc = other.docAdviceCategoriesDesc;
	}
	// 大类编码
	QString docAdviceCategoriesCode;
	// 大类名称
	QString	docAdviceCategoriesDesc;
};

/*****************************************************************************
* 医嘱子类结构体
*/
struct DocAdviceSubCat
{
	DocAdviceSubCat() = default;
	DocAdviceSubCat(const DocAdviceSubCat& other)
	{
		docAdviceSubCatCode = other.docAdviceSubCatCode;
		docAdviceSubCatDesc = other.docAdviceSubCatDesc;
		docAdviceSubCatUpper = other.docAdviceSubCatUpper;
	}
	// 子类编码
	QString docAdviceSubCatCode;
	// 子类名称
	QString	docAdviceSubCatDesc;
	// 大类编码
	QString docAdviceSubCatUpper;
};

/*****************************************************************************
* 收费大类结构体
*/
struct ChargeCategories
{
	ChargeCategories() = default;
	ChargeCategories(const ChargeCategories& other)
	{
		chargeCode = other.chargeCode;
		chargeDesc = other.chargeDesc;
	}
	// 大类编码
	QString chargeCode;
	// 大类名称
	QString	chargeDesc;
};

/*****************************************************************************
* 收费子类结构体
*/
struct ChargeSubCat
{
	ChargeSubCat() = default;
	ChargeSubCat(const ChargeSubCat& other)
	{
		chargeSubCatCode = other.chargeSubCatCode;
		chargeSubCatDesc = other.chargeSubCatDesc;
		chargeSubCatUpper = other.chargeSubCatUpper;
	}
	// 子类编码
	QString chargeSubCatCode;
	// 子类名称
	QString	chargeSubCatDesc;
	// 大类编码
	QString chargeSubCatUpper;
};

/*****************************************************************************
* 医嘱项目结构体
*/
struct DoctorDevice
{
	DoctorDevice() = default;
	DoctorDevice(const DoctorDevice& other)
	{
		doctorDeviceCode = other.doctorDeviceCode;
		doctorDeviceDesc = other.doctorDeviceDesc;
		doctorDeviceSubCat = other.doctorDeviceSubCat;
		doctorDeviceAbbrev = other.doctorDeviceAbbrev;
		doctorDeviceUom = other.doctorDeviceUom;
		doctorDeviceAllowOrderWOStockCheck = other.doctorDeviceAllowOrderWOStockCheck;
		doctorDeviceGeneric = other.doctorDeviceGeneric;
		doctorDeviceAntimicrobialAgents = other.doctorDeviceAntimicrobialAgents;
		doctorDeviceAntimicrobialAgentsType = other.doctorDeviceAntimicrobialAgentsType;
		doctorDeviceAntimicrobialAgentsDesc = other.doctorDeviceAntimicrobialAgentsDesc;
	}
	// 医嘱编码
	QString doctorDeviceCode{};
	// 医嘱名称
	QString	doctorDeviceDesc{};
	// 医嘱子类编码
	QString	doctorDeviceSubCat{};
	// 医嘱缩写
	QString	doctorDeviceAbbrev{};
	// 医嘱单位
	QString doctorDeviceUom{};
	// 无库存医嘱
	QString doctorDeviceAllowOrderWOStockCheck{};
	// 医嘱类别
	QString	doctorDeviceGeneric{};
	// 是否抗菌药
	QString	doctorDeviceAntimicrobialAgents{};
	// 抗菌药物类别
	QString	doctorDeviceAntimicrobialAgentsType{};
	// 抗菌药物备注
	QString	doctorDeviceAntimicrobialAgentsDesc{};
};

/*****************************************************************************
* 收费项目结构体
*/
struct ChargingProjects
{
	ChargingProjects() = default;
	ChargingProjects(const ChargingProjects& other)
	{
		chargingProjectsCode = other.chargingProjectsCode;
		chargingProjectsDesc = other.chargingProjectsDesc;
		chargingProjectsSubCat = other.chargingProjectsSubCat;
		chargingProjectsAbbrev = other.chargingProjectsAbbrev;
		chargingProjectsUom = other.chargingProjectsUom;
		chargingProjectsPric = other.chargingProjectsPric;
	}
	// 收费项目编码
	QString chargingProjectsCode{};
	// 收费项目名称
	QString	chargingProjectsDesc{};
	// 收费项目子类编码
	QString	chargingProjectsSubCat{};
	// 收费项目缩写
	QString	chargingProjectsAbbrev{};
	// 收费项目单位
	QString	chargingProjectsUom{};
	// 收费项目价格
	QString	chargingProjectsPric{};
};

/*****************************************************************************
* 医嘱项目与收费项目关联结构体
*/
struct DoctorDeviceAndChargingProjects
{
	DoctorDeviceAndChargingProjects() = default;
	DoctorDeviceAndChargingProjects(const DoctorDeviceAndChargingProjects& other)
	{
		doctorDeviceCode = other.doctorDeviceCode;
		doctorDeviceDesc = other.doctorDeviceDesc;
		chargingProjectsCode = other.chargingProjectsCode;
		chargingProjectsDesc = other.chargingProjectsDesc;
		doctorDeviceNum = other.doctorDeviceNum;
	}
	// 医嘱编码
	QString doctorDeviceCode{};
	// 医嘱名称
	QString	doctorDeviceDesc{};
	// 收费项目编码
	QString	chargingProjectsCode{};
	// 收费项目名称
	QString	chargingProjectsDesc{};
	// 收费项目数量
	QString	doctorDeviceNum{};
};

/*****************************************************************************
* 医保项目结构体
*/
struct InsuranceProjects
{
	// 医保项目编码
	QString insuranceProjectsCode{};
	// 医保项目名称
	QString	insuranceProjectsDesc{};
	// 医保项目类型（市医保，工伤）
	QString	insuranceProjectsType{};
	// 医保项目收费类别编码
	QString	insuranceProjectsChargeType{};
	// 医保项目拼音码
	QString	insuranceProjectsAbbrev{};
	// 甲类、乙类、丙类
	QString	insuranceProjectsTJXM{};
};

/*****************************************************************************
* 收费项目和医保项目对照结构体
*/
struct ChargeProjectAndInsuranceProject
{
	// 收费项目编码
	QString chargingProjectsCode{};
	// 收费项目名称
	QString	chargingProjectsDesc{};
	// 医保项目编码
	QString	insuranceProjectsCode{};
	// 医保项目名称
	QString	insuranceProjectsDesc{};
	// 医保项目类型（市医保，工伤）
	QString	insuranceProjectsType{};
};


/*****************************************************************************
* 卡类型结构体
*/
struct CardType
{
	// 卡类型编码
	QString cardTypeCode{};
	// 卡类型名称
	QString	cardTypeDesc{};
};

#endif // !EMERGENCYSYSTEM_STRUCTURE_H

