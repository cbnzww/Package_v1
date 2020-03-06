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

/********** 测试代码 **********/

struct data /*定义结构体*/
{
	int year, month, day;
};

struct stu /*定义结构体*/
{
	char name[20];
	long num;
	struct data birthday; /*嵌套的结构体类型成员*/

};

/********** 测试代码 **********/

class resource_package : public QWidget
{
	Q_OBJECT

public:
	resource_package(QWidget *parent = 0);
	~resource_package();
	void CreatePackageInfoXml();

	/********** 测试代码 **********/

	void CreateMyXml_Test1(Params* Params);
	void CreateMyXml_Test2();

	/********** 测试代码 **********/

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
