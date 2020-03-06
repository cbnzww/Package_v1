#include "resource_package.h"
#include <QtWidgets/QApplication>

struct Params Params[4] = {
	{ "component.id","xres" },
	{ "component.compatibility.minor.version","1.6.1" },
	{ "component.compatibility.minor.action","warn" },
	{ "unpack.dir","./bin" }
};

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	resource_package w;
	//w.CreatePackageInfoXml();
	//w.CreateMyXml(Params);
	w.show();
	return a.exec();
}
