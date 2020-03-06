#include "resource_package.h"
#include "Markup.h"
#include <qfile.h>
#include <qprocess.h>
#include <qmessagebox.h>


resource_package::resource_package(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton3_Confrim, &QPushButton::clicked, this, [=]() 
	{
		QString Device_Access_Protocol = ui.lineEdit1_Device_Access_Protocol->text();
		QString Data_Access_Protocol = ui.lineEdit2_Data_Access_Protocol->text();
		QString Manufacturer_Name_CN = ui.lineEdit3_Manufacturer_Name_CN->text();
		QString Manufacturer_Name_US = ui.lineEdit4_Manufacturer_Name_US->text();

		std::string strDevice_Access_Protocol = Device_Access_Protocol.toStdString();
		std::string strData_Access_Protocol = Data_Access_Protocol.toStdString();
		QByteArray strManufacturer_Name_CN = Manufacturer_Name_CN.toLocal8Bit();
		std::string strManufacturer_Name_US = Manufacturer_Name_US.toStdString();

		m_Device_Access_Protocol = strDevice_Access_Protocol.c_str();
		m_Data_Access_Protocol = strData_Access_Protocol.c_str();
		m_Manufacturer_Name_CN = strManufacturer_Name_CN.data();
		m_Manufacturer_Name_US = strManufacturer_Name_US.c_str();

		//CreatePackageInfoXml();
		//CreateMyXml_Test2();
		
		//DoReplace("D:\\packageinfo_1.xml", "{1}", "dhsdk_net");
		//DoReplace("D:\\packageinfo_1.xml", "{2}", "dhsdk");
		//DoReplace("D:\\packageinfo_1.xml", "{3}", "大华");
		//DoReplace("D:\\packageinfo_1.xml", "{4}", "dahua");

		//Replace_File("D:\\Generate_Device_Resource_Pack_Program\\Dynamic_device_access_resource_package\\xres_resource_{1}_{2}_1.0.0\\META-INF\\packageinfo.xml",
		//	"D:\\Generate_Device_Resource_Pack_Program\\xres_resource_dhsdk_net_dahuasdk_1.0.0\\META-INF\\packageinfo.xml");
		//Zip_File("D:\\Generate_Device_Resource_Pack_Program\\xres_resource_dhsdk_net_dahuasdk_1.0.0",
		//	"D:\\Generate_Device_Resource_Pack_Program\\xres_resource_dhsdk_net_dahuasdk_1.0.0.zip");
		//Unzip_File("D:\\Generate_Device_Resource_Pack_Program\\Dynamic_device_access_resource_package\\xres_resource_{1}_{2}_1.0.0\\xres-trigger\\lib\\xres-resource-acess-{2}-1.0-SNAPSHOT.jar",
		//	"D:\\Generate_Device_Resource_Pack_Program\\xres-resource-acess-{2}-1.0-SNAPSHOT");
		Unjar_File();
		//Unpack();
		//Test_Ping();


	});
}

resource_package::~resource_package()
{

}

void resource_package::CreatePackageInfoXml()
{
	QString PackageId = QString("xres_resource_") + m_Device_Access_Protocol + QString("_") + m_Data_Access_Protocol;
	std::string strPackageId = PackageId.toStdString();
	const char* cPackageId = strPackageId.c_str();

	const char* cTemp = "设备接入相关配置";
	std::string strParam1_Value = m_Manufacturer_Name_CN + std::string(cTemp);
	const char* cParam1_Value = strParam1_Value.c_str();

	QString Param2_Value = QString("xres ") + m_Manufacturer_Name_US + QString(" acess config");
	std::string strParam2_Value = Param2_Value.toStdString();
	const char* cParam2_Value = strParam2_Value.c_str();

	CMarkupSTL PackageInfoXml;

	PackageInfoXml.SetDoc("<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n");

	PackageInfoXml.AddElem("packageinfo");
	PackageInfoXml.AddAttrib("docVersion", "0.5.0");
	PackageInfoXml.AddAttrib("\nxmlns", "http://www.hikvision.com/compomentModel/0.5.0/packageinfo");
	PackageInfoXml.AddAttrib("\nxmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
	PackageInfoXml.AddAttrib("\nxsi:schemaLocation", "http://www.hikvision.com/compomentModel/0.5.0/packageinfo ../../schema/0.5.0/packageinfo.xsd");

	PackageInfoXml.IntoElem();
	PackageInfoXml.AddElem("package");
	PackageInfoXml.AddAttrib("type", "resourcePack");
	PackageInfoXml.AddAttrib("id", cPackageId);
	PackageInfoXml.AddAttrib("version", "1.0.0");

	PackageInfoXml.AddElem("params");
	PackageInfoXml.IntoElem();
	PackageInfoXml.AddElem("param");
	PackageInfoXml.AddAttrib("id", "displayName.zh_CN");
	PackageInfoXml.AddAttrib("value", cParam1_Value);
	PackageInfoXml.AddElem("param");
	PackageInfoXml.AddAttrib("id", "displayName.en_US");
	PackageInfoXml.AddAttrib("value", cParam2_Value);
	PackageInfoXml.AddElem("param");
	PackageInfoXml.AddAttrib("id", "component.id");
	PackageInfoXml.AddAttrib("value", "xres");
	PackageInfoXml.AddElem("param");
	PackageInfoXml.AddAttrib("id", "component.compatibility.minor.version");
	PackageInfoXml.AddAttrib("value", "1.6.1");
	PackageInfoXml.AddElem("param");
	PackageInfoXml.AddAttrib("id", "component.compatibility.minor.action");
	PackageInfoXml.AddAttrib("value", "warn");
	PackageInfoXml.AddElem("param");
	PackageInfoXml.AddAttrib("id", "unpack.dir");
	PackageInfoXml.AddAttrib("value", "./bin");
	PackageInfoXml.OutOfElem();
	PackageInfoXml.OutOfElem();

	PackageInfoXml.Save("D:\\packageinfo_test1.xml");
}

/********** 测试代码 **********/

void resource_package::CreateMyXml_Test1(Params* Params)
{
	CMarkupSTL PackageInfoXml;

	//PackageInfoXml.Load("C:\\Users\caobonan\\Desktop\\Qt_Xml_Task\\动态设备接入资源包\\xres_resource_{1}_{2}_1.0.0\\META-INF\\packageinfo.xml");

	PackageInfoXml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
	PackageInfoXml.AddElem("packageinfo");
	PackageInfoXml.AddAttrib("docVersion", "0.5.0");
	PackageInfoXml.AddAttrib("\nxmlns", "http://www.hikvision.com/compomentModel/0.5.0/packageinfo");
	PackageInfoXml.AddAttrib("\nxmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
	PackageInfoXml.AddAttrib("\nxsi:schemaLocation", "http://www.hikvision.com/compomentModel/0.5.0/packageinfo ../../schema/0.5.0/packageinfo.xsd");

	PackageInfoXml.IntoElem();
	//PackageInfoXml.SetDoc("<!--\n说明见资源包描述\n-->");

	PackageInfoXml.AddElem("package");

	//PackageInfoXml.SetDoc("<!--\nminor + reject 表示最低版本要求, 驱动包对接入组件有最低版本要求\n-->");

	PackageInfoXml.AddElem("params");
	for (int i = 0; i < sizeof(Params); i++)/*采用指针法输出数组元素的各成员*/
	{
		PackageInfoXml.IntoElem();
		PackageInfoXml.AddElem("param");
		PackageInfoXml.AddAttrib("id", Params[i].s_Id);
		PackageInfoXml.AddAttrib("value", Params[i].s_Value);

		PackageInfoXml.OutOfElem();
	}

	PackageInfoXml.Save("D:\\packageinfo.xml");
}

void resource_package::CreateMyXml_Test2()
{
	CMarkupSTL PackageInfoXml;

	PackageInfoXml.Load("D:\\packageinfo.xml");

	PackageInfoXml.AddElem("packageinfo");
	PackageInfoXml.AddAttrib("docVersion", "0.5.0");
	PackageInfoXml.AddAttrib("\nxmlns", "http://www.hikvision.com/compomentModel/0.5.0/packageinfo");
	PackageInfoXml.AddAttrib("\nxmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
	PackageInfoXml.AddAttrib("\nxsi:schemaLocation", "http://www.hikvision.com/compomentModel/0.5.0/packageinfo ../../schema/0.5.0/packageinfo.xsd");

	PackageInfoXml.Save("D:\\packageinfo_test2.xml");

}

bool resource_package::DoReplace(const QString & path, const QString & src, const QString & dst)
{
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}
	QByteArray line = file.readAll();
	QString srcData;
	srcData.prepend(line);
	if (srcData.contains(src))
	{
		srcData.replace(src, dst);
	}

	QFile file2;
	file2.setFileName("D:\\packageinfo_21.xml");
	bool isOK = file2.open(QIODevice::WriteOnly | QIODevice::Truncate);
	if (isOK == true)
	{
		file2.write(srcData.toStdString().data());
	}

	file.close();
	file2.close();
	return true;
}

bool resource_package::Replace_File(const QString & frompath, const QString & topath)
{
	QString srcData;
	QFile fromfile(frompath);
	if (!fromfile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}
	QByteArray text = fromfile.readAll();
	srcData.prepend(text);
	if (srcData.contains("{1}"))
	{
		srcData.replace("{1}", "dhsdk_net");
	}
	if (srcData.contains("{2}"))
	{
		srcData.replace("{2}", "dhsdk");
	}
	if (srcData.contains("{3}"))
	{
		const char* s = "大华";
		QString qs = QString::fromLocal8Bit(s);
		srcData.replace("{3}", qs);
	}
	if (srcData.contains("{4}"))
	{
		srcData.replace("{4}", "dahua");
	}
	fromfile.close();

	QFile tofile(topath);
	if (tofile.open(QIODevice::WriteOnly))
	{
		tofile.write(srcData.toStdString().data());
		tofile.close();
		return true;
	}
	return false;
}

bool resource_package::Zip_File(const QString & frompath, const QString & topath)
{
	QFile infile(frompath);
	QFile outfile(topath);
	infile.open(QIODevice::ReadOnly);
	outfile.open(QIODevice::WriteOnly);
	QByteArray uncompressedData = infile.readAll();
	QByteArray compressedData = qCompress(uncompressedData, 9);
	outfile.write(compressedData);
	infile.close();
	outfile.close();
	return false;
}

bool resource_package::Unzip_File(const QString & frompath, const QString & topath)
{
	QFile infile(frompath);
	QFile outfile(topath);
	infile.open(QIODevice::ReadOnly);
	outfile.open(QIODevice::WriteOnly);
	QByteArray uncompressedData = infile.readAll();
	QByteArray compressedData = qUncompress(uncompressedData);
	outfile.write(compressedData);
	infile.close();
	outfile.close();
	return false;
}

bool resource_package::Unjar_File()
{
	QProcess pJar(0);
	
	QString strJar;
	//strJar.append("D:\\Generate_Device_Resource_Pack_Program\\Package_v2\\jar\\jar.exe");
	strJar = "D:\\Generate_Device_Resource_Pack_Program\\Package_v2\\jar\\jar.exe xvf D:\\Generate_Device_Resource_Pack_Program\\Dynamic_device_access_resource_package\\xres_resource_{1}_{2}_1.0.0\\xres-trigger\\lib\\xres-resource-acess-{2}-1.0-SNAPSHOT.jar";
	//QStringList strCmd;
	//strCmd.append("jar");
	//strCmd.append("xvf");
	//strCmd.append("D:\\Generate_Device_Resource_Pack_Program\\Dynamic_device_access_resource_package\\xres_resource_{1}_{2}_1.0.0\\xres-trigger\\lib\\xres-resource-acess-{2}-1.0-SNAPSHOT.jar");

	pJar.start(strJar);
	pJar.waitForStarted();
	pJar.waitForFinished();
	QString strTemp = QString::fromLocal8Bit(pJar.readAllStandardOutput());

	QMessageBox testMassage1;
	testMassage1.setText(strTemp);
	testMassage1.exec();
	return true;
}

void resource_package::Unpack()
{
	QProcess pExe(0);
	QString str7z;
	//命令exe
	str7z.append("D:\\Generate_Device_Resource_Pack_Program\\Package_v2\\jar\\7za.exe");

	//命令参数
	QStringList strCMD;
	strCMD.append("x");
	strCMD.append("D:\\Generate_Device_Resource_Pack_Program\\Package_v2\\jar\\111.zip");

	//引用参数
	QString strArg;
	strArg.append("-y");
	strArg.append("-o");
	strArg.append("D:\\Generate_Device_Resource_Pack_Program\\Package_v2\\jar");
	strArg.append("*.txt");
	strArg.append("-r");

	pExe.setNativeArguments(strArg);

	pExe.start(str7z, strCMD);
	pExe.waitForStarted();
	pExe.waitForFinished();
	QString strTemp = QString::fromLocal8Bit(pExe.readAllStandardOutput());

	QMessageBox testMassage1;
	testMassage1.setText(strTemp);
	testMassage1.exec();
}

void resource_package::Test_Ping()
{
	QProcess p(0);
	p.start("cmd", QStringList() << "/c" << "ping www.baidu.com");
	p.waitForStarted();
	p.waitForFinished();
	QString strTemp = QString::fromLocal8Bit(p.readAllStandardOutput());

	QMessageBox testMassage;
	testMassage.setText(strTemp);
	testMassage.exec();
}

/********** 测试代码 **********/
