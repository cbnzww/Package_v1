/********************************************************************************
** Form generated from reading UI file 'resource_package.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESOURCE_PACKAGE_H
#define UI_RESOURCE_PACKAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resource_packageClass
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label1_Device_Access_Protocol;
    QLabel *label2_Data_Access_Protocol;
    QLabel *label3_Manufacturer_Name_CN;
    QLabel *label4_Manufacturer_Name_US;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit1_Device_Access_Protocol;
    QLineEdit *lineEdit2_Data_Access_Protocol;
    QLineEdit *lineEdit3_Manufacturer_Name_CN;
    QLineEdit *lineEdit4_Manufacturer_Name_US;
    QPushButton *pushButton1_Cancel;
    QPushButton *pushButton3_Confrim;
    QPushButton *pushButton2_Reset;

    void setupUi(QWidget *resource_packageClass)
    {
        if (resource_packageClass->objectName().isEmpty())
            resource_packageClass->setObjectName(QStringLiteral("resource_packageClass"));
        resource_packageClass->resize(800, 600);
        verticalLayoutWidget = new QWidget(resource_packageClass);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(210, 160, 160, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label1_Device_Access_Protocol = new QLabel(verticalLayoutWidget);
        label1_Device_Access_Protocol->setObjectName(QStringLiteral("label1_Device_Access_Protocol"));
        label1_Device_Access_Protocol->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label1_Device_Access_Protocol);

        label2_Data_Access_Protocol = new QLabel(verticalLayoutWidget);
        label2_Data_Access_Protocol->setObjectName(QStringLiteral("label2_Data_Access_Protocol"));
        label2_Data_Access_Protocol->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label2_Data_Access_Protocol);

        label3_Manufacturer_Name_CN = new QLabel(verticalLayoutWidget);
        label3_Manufacturer_Name_CN->setObjectName(QStringLiteral("label3_Manufacturer_Name_CN"));
        label3_Manufacturer_Name_CN->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label3_Manufacturer_Name_CN);

        label4_Manufacturer_Name_US = new QLabel(verticalLayoutWidget);
        label4_Manufacturer_Name_US->setObjectName(QStringLiteral("label4_Manufacturer_Name_US"));
        label4_Manufacturer_Name_US->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label4_Manufacturer_Name_US);

        verticalLayoutWidget_2 = new QWidget(resource_packageClass);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(370, 160, 160, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit1_Device_Access_Protocol = new QLineEdit(verticalLayoutWidget_2);
        lineEdit1_Device_Access_Protocol->setObjectName(QStringLiteral("lineEdit1_Device_Access_Protocol"));

        verticalLayout_2->addWidget(lineEdit1_Device_Access_Protocol);

        lineEdit2_Data_Access_Protocol = new QLineEdit(verticalLayoutWidget_2);
        lineEdit2_Data_Access_Protocol->setObjectName(QStringLiteral("lineEdit2_Data_Access_Protocol"));

        verticalLayout_2->addWidget(lineEdit2_Data_Access_Protocol);

        lineEdit3_Manufacturer_Name_CN = new QLineEdit(verticalLayoutWidget_2);
        lineEdit3_Manufacturer_Name_CN->setObjectName(QStringLiteral("lineEdit3_Manufacturer_Name_CN"));

        verticalLayout_2->addWidget(lineEdit3_Manufacturer_Name_CN);

        lineEdit4_Manufacturer_Name_US = new QLineEdit(verticalLayoutWidget_2);
        lineEdit4_Manufacturer_Name_US->setObjectName(QStringLiteral("lineEdit4_Manufacturer_Name_US"));

        verticalLayout_2->addWidget(lineEdit4_Manufacturer_Name_US);

        pushButton1_Cancel = new QPushButton(resource_packageClass);
        pushButton1_Cancel->setObjectName(QStringLiteral("pushButton1_Cancel"));
        pushButton1_Cancel->setGeometry(QRect(230, 390, 75, 23));
        pushButton3_Confrim = new QPushButton(resource_packageClass);
        pushButton3_Confrim->setObjectName(QStringLiteral("pushButton3_Confrim"));
        pushButton3_Confrim->setGeometry(QRect(440, 390, 75, 23));
        pushButton2_Reset = new QPushButton(resource_packageClass);
        pushButton2_Reset->setObjectName(QStringLiteral("pushButton2_Reset"));
        pushButton2_Reset->setGeometry(QRect(330, 390, 75, 23));

        retranslateUi(resource_packageClass);
        QObject::connect(pushButton1_Cancel, SIGNAL(clicked()), resource_packageClass, SLOT(close()));

        QMetaObject::connectSlotsByName(resource_packageClass);
    } // setupUi

    void retranslateUi(QWidget *resource_packageClass)
    {
        resource_packageClass->setWindowTitle(QApplication::translate("resource_packageClass", "resource_package", Q_NULLPTR));
        label1_Device_Access_Protocol->setText(QApplication::translate("resource_packageClass", "\350\256\276\345\244\207\346\216\245\345\205\245\345\215\217\350\256\256", Q_NULLPTR));
        label2_Data_Access_Protocol->setText(QApplication::translate("resource_packageClass", "\346\225\260\346\215\256\346\216\245\345\205\245\345\215\217\350\256\256", Q_NULLPTR));
        label3_Manufacturer_Name_CN->setText(QApplication::translate("resource_packageClass", "\345\216\202\345\225\206\344\270\255\346\226\207\345\220\215\347\247\260", Q_NULLPTR));
        label4_Manufacturer_Name_US->setText(QApplication::translate("resource_packageClass", "\345\216\202\345\225\206\350\213\261\346\226\207\345\220\215\347\247\260", Q_NULLPTR));
        pushButton1_Cancel->setText(QApplication::translate("resource_packageClass", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton3_Confrim->setText(QApplication::translate("resource_packageClass", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton2_Reset->setText(QApplication::translate("resource_packageClass", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class resource_packageClass: public Ui_resource_packageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESOURCE_PACKAGE_H
