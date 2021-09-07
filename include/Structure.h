/****************************************************************************
*							 �ṹ��洢
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
	// ����
	QString ProvinceCityCountryCode{};
	// ����
	QString ProvinceCityCountryDescription{};
	// �ϲ����
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
	// ����
	QString sexId{};
	// ����
	QString sexDescription{};
	// Ԥ���ֶ�
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
	// ����
	QString hospitalCode{};
	// ����
	QString hospitalDescription{};
	// Ԥ���ֶ�
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
	// ҽ����Ա����
	QString medicalStaffCode{};
	// ҽ����Ա����
	QString medicalStaffName{};
	// ҽ����Ա�Ա�
	int medicalStaffSex{};
	// ҽ����Ա��ַ
	QString medicalStaffAddress{};
	// ҽ����Ա�ʸ�֤��
	QString medicalStaffDoctorNo{};
	// ҽ����Աҽ����Ա����
	QString medicalStaffInsuDoctorNo{};
	// ҽ����Ա����
	QString medicalStaffType{};
	// ҽ����Ա�绰
	QString medicalStaffTelephone{};
	// ҽ����Ա�Ƿ�����ҽ��
	QString medicalStaffAnaesthetist{};
	// ҽ����Ա�Ƿ����ҽ��
	QString medicalStaffSurgeon{};
	// ҽ����Ա��������
	QString medicalStaffLoc{};
	// ҽ����Ա��������
	QString medicalStaffWard{};
	// ҽ����Աְ��
	QString medicalStaffTitle{};
	// ҽ����Ա����Ժ��
	QString medicalStaffHospital{};
};

/*****************************************************************************
* ���ұ�ṹ��
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
	// ���ұ���
	QString departmentCode{};
	// ��������
	QString departmentDescription{};
	// �Ƿ�Ϊ����
	QString	departmentWardFlag{};
	// ���ҵ�ַ
	QString	departmentAddress{};
	// ��������
	QString	departmentType{};
	// ����������
	QString	departmentGroup{};
	// ����Ժ��
	QString	departmentHospital{};
	// �����Ƿ���Ч
	QString	departmentValid{};
	// ��������ʱ��
	QString	departmentStartTime{};
	// ������ֹʱ��
	QString	departmentEndTime{};
};

/*****************************************************************************
* �������ͽṹ��
*/
struct DepartmentType
{
	DepartmentType() = default;
	DepartmentType(const DepartmentType& other)
	{
		departmentTypeCode = other.departmentTypeCode;
		departmentTypeDescription = other.departmentTypeDescription;
	}
	// ���ͱ���
	QString departmentTypeCode;
	// ��������
	QString	departmentTypeDescription;
};

/*****************************************************************************
* ҽ�����ҹ����ṹ��
*/
struct DoctorAndDepartment
{
	DoctorAndDepartment() = default;
	DoctorAndDepartment(const DoctorAndDepartment& other)
	{
		doctorAndDepartmentDocCode = other.doctorAndDepartmentDocCode;
		doctorAndDepartmentDepCode = other.doctorAndDepartmentDepCode;
	}
	// ҽ������
	QString doctorAndDepartmentDocCode;
	// ���ұ���
	QString	doctorAndDepartmentDepCode;
};

/*****************************************************************************
* ҽ������ṹ��
*/
struct DocAdviceCategories
{
	DocAdviceCategories() = default;
	DocAdviceCategories(const DocAdviceCategories& other)
	{
		docAdviceCategoriesCode = other.docAdviceCategoriesCode;
		docAdviceCategoriesDesc = other.docAdviceCategoriesDesc;
	}
	// �������
	QString docAdviceCategoriesCode;
	// ��������
	QString	docAdviceCategoriesDesc;
};

/*****************************************************************************
* ҽ������ṹ��
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
	// �������
	QString docAdviceSubCatCode;
	// ��������
	QString	docAdviceSubCatDesc;
	// �������
	QString docAdviceSubCatUpper;
};

/*****************************************************************************
* �շѴ���ṹ��
*/
struct ChargeCategories
{
	ChargeCategories() = default;
	ChargeCategories(const ChargeCategories& other)
	{
		chargeCode = other.chargeCode;
		chargeDesc = other.chargeDesc;
	}
	// �������
	QString chargeCode;
	// ��������
	QString	chargeDesc;
};

/*****************************************************************************
* �շ�����ṹ��
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
	// �������
	QString chargeSubCatCode;
	// ��������
	QString	chargeSubCatDesc;
	// �������
	QString chargeSubCatUpper;
};

/*****************************************************************************
* ҽ����Ŀ�ṹ��
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
	// ҽ������
	QString doctorDeviceCode{};
	// ҽ������
	QString	doctorDeviceDesc{};
	// ҽ���������
	QString	doctorDeviceSubCat{};
	// ҽ����д
	QString	doctorDeviceAbbrev{};
	// ҽ����λ
	QString doctorDeviceUom{};
	// �޿��ҽ��
	QString doctorDeviceAllowOrderWOStockCheck{};
	// ҽ�����
	QString	doctorDeviceGeneric{};
	// �Ƿ񿹾�ҩ
	QString	doctorDeviceAntimicrobialAgents{};
	// ����ҩ�����
	QString	doctorDeviceAntimicrobialAgentsType{};
	// ����ҩ�ﱸע
	QString	doctorDeviceAntimicrobialAgentsDesc{};
};

/*****************************************************************************
* �շ���Ŀ�ṹ��
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
	// �շ���Ŀ����
	QString chargingProjectsCode{};
	// �շ���Ŀ����
	QString	chargingProjectsDesc{};
	// �շ���Ŀ�������
	QString	chargingProjectsSubCat{};
	// �շ���Ŀ��д
	QString	chargingProjectsAbbrev{};
	// �շ���Ŀ��λ
	QString	chargingProjectsUom{};
	// �շ���Ŀ�۸�
	QString	chargingProjectsPric{};
};

/*****************************************************************************
* ҽ����Ŀ���շ���Ŀ�����ṹ��
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
	// ҽ������
	QString doctorDeviceCode{};
	// ҽ������
	QString	doctorDeviceDesc{};
	// �շ���Ŀ����
	QString	chargingProjectsCode{};
	// �շ���Ŀ����
	QString	chargingProjectsDesc{};
	// �շ���Ŀ����
	QString	doctorDeviceNum{};
};

/*****************************************************************************
* ҽ����Ŀ�ṹ��
*/
struct InsuranceProjects
{
	// ҽ����Ŀ����
	QString insuranceProjectsCode{};
	// ҽ����Ŀ����
	QString	insuranceProjectsDesc{};
	// ҽ����Ŀ���ͣ���ҽ�������ˣ�
	QString	insuranceProjectsType{};
	// ҽ����Ŀ�շ�������
	QString	insuranceProjectsChargeType{};
	// ҽ����Ŀƴ����
	QString	insuranceProjectsAbbrev{};
	// ���ࡢ���ࡢ����
	QString	insuranceProjectsTJXM{};
};

/*****************************************************************************
* �շ���Ŀ��ҽ����Ŀ���սṹ��
*/
struct ChargeProjectAndInsuranceProject
{
	// �շ���Ŀ����
	QString chargingProjectsCode{};
	// �շ���Ŀ����
	QString	chargingProjectsDesc{};
	// ҽ����Ŀ����
	QString	insuranceProjectsCode{};
	// ҽ����Ŀ����
	QString	insuranceProjectsDesc{};
	// ҽ����Ŀ���ͣ���ҽ�������ˣ�
	QString	insuranceProjectsType{};
};


/*****************************************************************************
* �����ͽṹ��
*/
struct CardType
{
	// �����ͱ���
	QString cardTypeCode{};
	// ����������
	QString	cardTypeDesc{};
};

#endif // !EMERGENCYSYSTEM_STRUCTURE_H

