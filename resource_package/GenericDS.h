/*
 * @file  GenericDS.h
 * @note  Hikvision Digital Technology Co., Ltd. All Rights Reserved 
 * @brief XML操作类
 * 
 * @author shengchangchun 
 * @date   2010-8-10
 * 
 * @note 
 * @note 
 */

#ifndef _IVMSGUI_GENERICDS_H
#define _IVMSGUI_GENERICDS_H

#include "iVMSGUIToolkitGlobal.h"
#include <QtXml/QDomDocument>

namespace iVMSGUIToolkit
{
	/** @class CGenericDS
	  * @brief 封装xml节点
	  */
	class iVMS_GUI_EXPORT CGenericDS
	{
	public:
		// 构造函数
		CGenericDS(void);
		// 析够
		~CGenericDS(void);

	public:
		////////////////////////////////////////////////////
		// 读取部分                           ////
		///////////////////////////////////////////////////
		// 读取XML文件
		bool LoadXML(const QString& strFileName);
		// 读取xml文件
		bool PhaseXml(const QString& strXMl);
		QString GetXml();

		// 获得子节点数量
		int GetChildrenCount() const;
		// 获取子节点
		CGenericDS GetChild(int iIndex) const;
		// 获取子节点
		CGenericDS GetChildByName(const QString& strName) const;

		// 获取节点名称
		QString GetName() const;
        // 获取值
        bool GetValue(QString& strValue) const;
        QString GetValue() const;
		// 获取key值为strKeyName对应的值
		QString GetAttribute(const QString& strKeyName, const QString& strDefValue = QString()) const;
		
	public:
		////////////////////////////////////////////////////
		// 保存xml部分                           ////
		///////////////////////////////////////////////////
		// 保存文件
		bool SaveXML(const QString& strFileName);
		// 添加为根节点
		bool CreateASRoot(const QString& strName);

		// 添加为子节点
		CGenericDS CreateChild(const QString& strName);

        // 删除子节点
        bool RemoveChild(const QString& strName);
        
        // 删除子节点
        bool RemoveChild(int iIndex);

		// 设置当前节点名
		bool SetValue(const QString& strValue);
		// 设置当前节点名以及值
		bool SetAttribute(const QString& strName, const QString& strValue);

	private:
		QDomElement m_domElement;
        QDomDocument m_pDomDocument;
	};
}

#endif // _IVMSGUI_GENERICDS_H
