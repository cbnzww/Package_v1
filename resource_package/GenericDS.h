/*
 * @file  GenericDS.h
 * @note  Hikvision Digital Technology Co., Ltd. All Rights Reserved 
 * @brief XML������
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
	  * @brief ��װxml�ڵ�
	  */
	class iVMS_GUI_EXPORT CGenericDS
	{
	public:
		// ���캯��
		CGenericDS(void);
		// ����
		~CGenericDS(void);

	public:
		////////////////////////////////////////////////////
		// ��ȡ����                           ////
		///////////////////////////////////////////////////
		// ��ȡXML�ļ�
		bool LoadXML(const QString& strFileName);
		// ��ȡxml�ļ�
		bool PhaseXml(const QString& strXMl);
		QString GetXml();

		// ����ӽڵ�����
		int GetChildrenCount() const;
		// ��ȡ�ӽڵ�
		CGenericDS GetChild(int iIndex) const;
		// ��ȡ�ӽڵ�
		CGenericDS GetChildByName(const QString& strName) const;

		// ��ȡ�ڵ�����
		QString GetName() const;
        // ��ȡֵ
        bool GetValue(QString& strValue) const;
        QString GetValue() const;
		// ��ȡkeyֵΪstrKeyName��Ӧ��ֵ
		QString GetAttribute(const QString& strKeyName, const QString& strDefValue = QString()) const;
		
	public:
		////////////////////////////////////////////////////
		// ����xml����                           ////
		///////////////////////////////////////////////////
		// �����ļ�
		bool SaveXML(const QString& strFileName);
		// ���Ϊ���ڵ�
		bool CreateASRoot(const QString& strName);

		// ���Ϊ�ӽڵ�
		CGenericDS CreateChild(const QString& strName);

        // ɾ���ӽڵ�
        bool RemoveChild(const QString& strName);
        
        // ɾ���ӽڵ�
        bool RemoveChild(int iIndex);

		// ���õ�ǰ�ڵ���
		bool SetValue(const QString& strValue);
		// ���õ�ǰ�ڵ����Լ�ֵ
		bool SetAttribute(const QString& strName, const QString& strValue);

	private:
		QDomElement m_domElement;
        QDomDocument m_pDomDocument;
	};
}

#endif // _IVMSGUI_GENERICDS_H
