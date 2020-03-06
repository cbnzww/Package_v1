#ifndef RESOURCE_PACKAGE_H
#define RESOURCE_PACKAGE_H

#include <QtWidgets/QWidget>
#include "ui_resource_package.h"

struct Params
{
	char* s_Id;
	char* s_Value;
};

struct PackageInfo
{
	std::string s_Type;
	std::string s_Id;
	std::string s_Version;
	struct Params st_Params;
};

/********** ���Դ��� **********/

struct data /*����ṹ��*/
{
	int year, month, day;
};

struct stu /*����ṹ��*/
{
	char name[20];
	long num;
	struct data birthday; /*Ƕ�׵Ľṹ�����ͳ�Ա*/

};

/********** ���Դ��� **********/

class resource_package : public QWidget
{
	Q_OBJECT

public:
	resource_package(QWidget *parent = 0);
	~resource_package();
	void CreatePackageInfoXml();

	/********** ���Դ��� **********/

	void CreateMyXml_Test1(Params* Params);
	void CreateMyXml_Test2();

	/********** ���Դ��� **********/

	bool DoReplace(const QString &path, const QString &src,const QString &dst);
	bool Replace_File(const QString &frompath, const QString & topath);
	bool Zip_File(const QString& frompath, const QString& topath);
	bool Unzip_File(const QString& frompath, const QString& topath);
	bool Unjar_File();
	void Unpack();
	void Test_Ping();
private:
	Ui::resource_packageClass ui;

	const char* m_Device_Access_Protocol;
	const char* m_Data_Access_Protocol;
	const char* m_Manufacturer_Name_CN;
	const char* m_Manufacturer_Name_US;
};

#endif // RESOURCE_PACKAGE_H
