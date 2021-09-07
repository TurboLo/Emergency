



### 表结构设计

#### 基础数据表

##### 1.患者基本信息表 Person

|           字段            | 字段类型 |      备注      |
| :-----------------------: | :------: | :------------: |
|        Patient_No         | char(20) | 患者唯一识别号 |
|       Patient_Name        | char(20) |    患者姓名    |
|        Patient_Sex        |   int    |    患者性别    |
|      Patient_Name_1       | char(20) |     曾用名     |
|       Patient_In_No       | char(20) |     住院号     |
|      Patient_Out_No       | char(20) |   门诊病历号   |
|   Patient_Insurance_No    | char(20) |     医保号     |
| Patient_Insurance_Card_No | char(20) |    医保卡号    |
|       Patient_ID_No       | char(20) |    身份证号    |
|       Patient_Alias       | char(20) |    患者别名    |
|     Patient_VIP_Flag      | char(20) |    VIP标志     |
|      Patient_Country      |   int    |     所在国     |
|     Patient_Province      |   int    |     所在省     |
|      Patient_Region       |   int    |    所在地区    |
|       Patient_Phone       | char(20) |      手机      |
|   Patient_Second_Phone    | char(20) |    第二手机    |
|  Patient_Health_Card_No   | char(20) |    健康卡号    |
|      Patient_Address      | char(50) |    患者住址    |

##### 2.性别表 Sex

|      字段       | 字段类型 |     备注     |
| :-------------: | :------: | :----------: |
|     Sex_id      |   int    |   性别数字   |
| Sex_Description | char(4)  |   性别描述   |
|    Sex_Other    | char(20) | 预留其他字段 |

##### 3.用户表 User

|     字段      | 字段类型 |      备注       |
| :-----------: | :------: | :-------------: |
|   User_Code   | char(20) |      工号       |
| User_Password | char(20) | 密码（默认为1） |
|   User_Name   | char(20) |      姓名       |

##### 4.省份表 Province

|         字段         | 字段类型 |       备注       |
| :------------------: | :------: | :--------------: |
|    Province_Code     | char(10) |     省份代码     |
| Province_Description | char(20) |     省份名称     |
|   Province_Country   | char(10) | 省份对应国家代码 |

##### 5.市级表 City

|       字段       | 字段类型 |      备注      |
| :--------------: | :------: | :------------: |
|    City_Code     | char(10) |     市代码     |
| City_Description | char(20) |     市名称     |
|  City_Province   | char(10) | 市对应省份代码 |

##### 6.区县表 County

|        字段        | 字段类型 |      备注      |
| :----------------: | :------: | :------------: |
|    County_Code     | char(10) |    区县代码    |
| County_Description | char(20) |    区县名称    |
|  County_Province   | char(10) | 区县对应市代码 |

##### 7.数据导入记录表 ImportDataTable

|            字段             | 字段类型 |         备注         |
| :-------------------------: | :------: | :------------------: |
|    ImportDataTable_Code     | char(20) | 需要导入数据的表名称 |
| ImportDataTable_Description | char(20) |         描述         |
|    ImportDataTable_Flag     |   int    |       导入状态       |

##### 8.医护人员表 MedicalStaff

|           字段            | 字段类型 |     备注     |
| :-----------------------: | :------: | :----------: |
|     MedicalStaff_Code     | char(20) |     工号     |
|     MedicalStaff_Name     | char(20) |     姓名     |
|     MedicalStaff_Sex      |   int    |     性别     |
|   MedicalStaff_Address    | char(50) |     地址     |
|   MedicalStaff_DoctorNo   | char(20) |   医师编码   |
| MedicalStaff_InsuDoctorNo | char(20) |  医保医生号  |
|     MedicalStaff_Type     |   int    | 医护人员类型 |
|  MedicalStaff_Telephone   | char(20) |     电话     |
| MedicalStaff_Anaesthetist |   int    | 是否麻醉医生 |
|   MedicalStaff_Surgeon    |   int    | 是否外科医生 |
|     MedicalStaff_Loc      | char(20) |   所属科室   |
|     MedicalStaff_Ward     | char(20) |   所属病区   |
|    MedicalStaff_Title     | char(20) |     职称     |
|   MedicalStaff_Hospital   | char(10) | 所属医院代码 |

##### 9.院区表 Hospital

|         字段         | 字段类型 |   备注   |
| :------------------: | :------: | :------: |
|    Hospital_Code     | char(20) | 医院编码 |
| Hospital_Description | char(20) | 医院描述 |
|    Hospital_Other    | Char(20) | 医院其他 |

##### 10.科室表 Department

|          字段          | 字段类型 |     备注     |
| :--------------------: | :------: | :----------: |
|    Department_Code     | char(20) |   科室编码   |
| Department_Description | char(20) |   科室描述   |
|  Department_WardFlag   |   int    |  是否为病区  |
|   Department_Address   | char(50) |   科室地址   |
|    Department_Type     | char(20) |   科室类型   |
|    Department_Group    | char(20) |  科室所属组  |
|  Department_Hospital   | char(10) |   所属院区   |
|    Department_Valid    |   int    | 科室是否有效 |
|  Department_StartTime  | char(20) | 科室设立时间 |
|   Department_EndTime   | char(20) | 科室终止时间 |

##### 11.科室类型表 DepartmentType

|            字段            | 字段类型 |   备注   |
| :------------------------: | :------: | :------: |
|    DepartmentType_Code     | char(20) | 类型编码 |
| DepartmentType_Description | char(20) | 类型描述 |

##### 12.医生科室关联表 DoctorAndDepartment

|            字段             | 字段类型 |   备注   |
| :-------------------------: | :------: | :------: |
| DoctorAndDepartment_DocCode | char(20) | 医生工号 |
| DoctorAndDepartment_DepCode | char(20) | 科室编码 |

##### 13.医嘱大类表 DocAdviceCategories

|           字段           | 字段类型 |   备注   |
| :----------------------: | :------: | :------: |
| DocAdviceCategories_Code | char(20) | 大类编码 |
| DocAdviceCategories_Desc | char(20) | 大类描述 |

##### 14.医嘱子类表 DocAdviceSubCat

|         字段          | 字段类型 |   备注   |
| :-------------------: | :------: | :------: |
| DocAdviceSubCat_Code  | char(20) | 子类编码 |
| DocAdviceSubCat_Desc  | char(20) | 子类描述 |
| DocAdviceSubCat_Upper | char(20) | 大类编码 |

##### 15.收费大类表 ChargeCategories

|    字段     | 字段类型 |   备注   |
| :---------: | :------: | :------: |
| Charge_Code | char(20) | 大类编码 |
| Charge_Desc | char(20) | 大类描述 |

##### 16.收费子类表 ChargeSubCat

|        字段        | 字段类型 |   备注   |
| :----------------: | :------: | :------: |
| ChargeSubCat_Code  | char(20) | 子类编码 |
| ChargeSubCat_Desc  | char(20) | 子类描述 |
| ChargeSubCat_Upper | char(20) | 大类编码 |

##### 17.医嘱项目表 DoctorDevice

|                 字段                 | 字段类型 |                       备注                       |
| :----------------------------------: | :------: | :----------------------------------------------: |
|          DoctorDevice_Code           | char(20) |                     医嘱编码                     |
|          DoctorDevice_Desc           | char(30) |                     医嘱名称                     |
|         DoctorDevice_SubCat          | char(20) |                   医嘱子类编码                   |
|         DoctorDevice_Abbrev          | char(20) |                     医嘱缩写                     |
|           DoctorDevice_Uom           | char(10) |                     医嘱单位                     |
| DoctorDevice_AllowOrderWOStockCheck  |   int    |      无库存医嘱（默认全部是是，不允许为否）      |
|         DoctorDevice_Generic         | char(10) | 医嘱类别（药物，材料，服务，中药等（便于统计）） |
|   DoctorDevice_AntimicrobialAgents   |   int    |                    是否抗菌药                    |
| DoctorDevice_AntimicrobialAgentsType | char(10) |                   抗菌药物类别                   |
| DoctorDevice_AntimicrobialAgentsDesc | char(50) |                   抗菌药物备注                   |

##### 18.收费项目表 ChargingProjects

|          字段           | 字段类型 |       备注       |
| :---------------------: | :------: | :--------------: |
|  ChargingProjects_Code  | char(20) |   收费项目编码   |
|  ChargingProjects_Desc  | char(20) |   收费项目名称   |
| ChargingProjects_SubCat | char(20) | 收费项目子类编码 |
| ChargingProjects_Abbrev | char(20) |   收费项目缩写   |
|  ChargingProjects_Uom   | char(10) |   收费项目单位   |
|  ChargingProjects_Pric  | char(20) |   收费项目价格   |

##### 19.医嘱项目与收费项目关联表 DoctorDeviceAndChargingProjects

|         字段          | 字段类型 |     备注     |
| :-------------------: | :------: | :----------: |
|   DoctorDevice_Code   | char(20) |   医嘱编码   |
|   DoctorDevice_Desc   | char(20) |   医嘱名称   |
| ChargingProjects_Code | char(20) | 收费项目编码 |
| ChargingProjects_Desc | char(20) | 收费项目名称 |
| ChargingProjects_Num  | char(10) | 收费项目数量 |

##### 20.医保项目表 InsuranceProjects

|             字段             | 字段类型 |             备注             |
| :--------------------------: | :------: | :--------------------------: |
|    InsuranceProjects_Code    | char(20) |         医保项目编码         |
|    InsuranceProjects_Desc    | char(20) |         医保项目名称         |
|    InsuranceProjects_Type    | char(20) | 医保项目类型（市医保，工伤） |
| InsuranceProjects_ChargeType | char(20) |     医保项目收费类别编码     |
|   InsuranceProjects_Abbrev   | char(10) |        医保项目拼音码        |
|    InsuranceProjects_TJXM    |   Int    |       甲类、乙类、丙类       |

##### 21.收费项目和医保项目对照表 ChargeProjectAndInsuranceProject

|          字段          | 字段类型 |             备注             |
| :--------------------: | :------: | :--------------------------: |
| ChargingProjects_Code  | char(20) |         收费项目编码         |
| ChargingProjects_Desc  | char(20) |         收费项目名称         |
| InsuranceProjects_Code | char(20) |         医保项目编码         |
| InsuranceProjects_Desc | char(20) |         医保项目名称         |
| InsuranceProjects_Type | char(20) | 医保项目类型（市医保，工伤） |

##### 22.卡类型表 CardType

|     字段      | 字段类型 |    备注    |
| :-----------: | :------: | :--------: |
| CardType_Code | char(20) | 卡类型编码 |
| CardType_Desc | char(20) | 卡类型名称 |

##### 23.人员类型表 PersonType

|       字段        | 字段类型 |     备注     |
| :---------------: | :------: | :----------: |
|  PersonType_Code  | char(20) | 人员类型编码 |
|  PersonType_Desc  | char(20) | 人员类型名称 |
| PersonType_IsInsu |   int    |   是否医保   |
