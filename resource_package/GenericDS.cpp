/*
 * @fileXML  GenericDS.cpp
 * @note  Hikvision Digital Technology Co., Ltd. All Rights Reserved 
 * @brief XML������
 * 
 * @author shengchangchun 
 * @date   2010-8-10
 * 
 * @note 
 * @note 
 */

#include "GenericDS.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QTextCodec>

namespace iVMSGUIToolkit
{
	//����
	CGenericDS::CGenericDS(void)
	{
	}

	//����
	CGenericDS::~CGenericDS(void)
	{
	}

	/** @fn    bool CGenericDS::LoadXML(const QString& strXMLName)
	  * @brief ����XML�ļ�
	  * @param <IN> const QString& strXMLName �� XML�ļ�
	  * @return bool ture - ����ɹ�  false - ����ʧ��.
	  */
	bool CGenericDS::LoadXML(const QString& strXMLName)
	{
        if (strXMLName.isNull())
        {
            return false;
        }

        //��xml�ļ�
        QFile fileXML(strXMLName);
        if (!fileXML.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }

        bool bRes = m_pDomDocument.setContent(&fileXML);
        fileXML.close();

        m_domElement = m_pDomDocument.documentElement();

		return true;
	}

	/**   @fn     PhaseXml 
	 *    @brief  ����xml�ı�
	 *    @param  (IN) const QString& strXMl -xml�ı���Ϣ
	 *    @return bool
	 */
	bool CGenericDS::PhaseXml(const QString& strXMl)
	{
		if (strXMl.isEmpty())
		{
			return false;
		}

		bool bRes = m_pDomDocument.setContent(strXMl);
		m_domElement = m_pDomDocument.documentElement();
		return bRes;
	}

	QString CGenericDS::GetXml()
	{
		return m_pDomDocument.toString();
	}


	/** @fn    bool CGenericDS::SaveXML(const QString& strXMLName)
	  * @brief ����xml
	  * @param <IN> const QString& strXMLName �� XML�ļ�
	  * @return bool ture - ����ɹ�  false - ����ʧ��.
	  */
	bool CGenericDS::SaveXML(const QString& strXMLName)
	{
        QFile fileXML(strXMLName);
        if (!fileXML.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return false;
        }

        //��ȡ�ı��� ���ñ���GB2312
        QTextStream textStreamOut (&fileXML);
        QTextCodec* pCodec = QTextCodec::codecForName("GB2312");
        textStreamOut.setCodec(pCodec);

        m_pDomDocument.save(textStreamOut, 0);

        fileXML.close();

        return true;
	}

	/** @fn int CGenericDS::GetChildrenCount() const
	 *  @brief  ��ȡ�ӽڵ�����
	 *  @param (IN) none.
	 *  @return int �ֽڵ�����
	 */ 
	int CGenericDS::GetChildrenCount() const
	{
		//��Ԫ�ش���
		if(m_domElement.isNull())
		{
			return 0;
		}

        int iEleNum = 0;

		//���ڽڵ�
		if(m_domElement.hasChildNodes()) //return locEle.childNodes().count();�ٶȲ���
		{
			for (QDomNode domNode = m_domElement.firstChild(); !domNode.isNull(); domNode = domNode.nextSibling())
			{
				if(domNode.isElement())
				{
					iEleNum++;
				}
			}
		}

		return iEleNum;
	}

	/** @fn CGenericDS CGenericDS::GetChild(int iIndex) const
	 *  @brief  ��ȡ�ӽڵ� ��������
	 *  @param (IN) iIndex - �ڼ����ֽڵ�.
	 *  @return CGenericDS �ڵ� 
	 */ 
	CGenericDS CGenericDS::GetChild(int iIndex) const
	{
		CGenericDS childDS;

		if(m_domElement.isNull())
		{
			return childDS;
		}

		int iEleNum = 0;
		if(m_domElement.hasChildNodes())
		{
			for (QDomNode domNode = m_domElement.firstChild(); !domNode.isNull(); domNode = domNode.nextSibling())
			{
				if(domNode.isElement())
				{
					if(iEleNum == iIndex)
					{
						childDS.m_domElement = domNode.toElement();
                        childDS.m_pDomDocument = m_pDomDocument;
						return childDS;
					}

					iEleNum++;
				}
			}
		}

		return childDS;
	}

	/** @fn    CGenericDS CGenericDS::GetChildByName(const QString& strName) const
	  * @brief ��ȡ�ӽڵ� ��������
	  * @param <IN> const QString& strName - ����.
	  * @return CGenericDS �ڵ� 
	  */
	CGenericDS CGenericDS::GetChildByName(const QString& strName) const
	{
		CGenericDS childDS;
		if(m_domElement.hasChildNodes())
		{
			QDomNodeList listNode = m_domElement.elementsByTagName(strName);
			if (listNode.count() != 0) 
			{
				childDS.m_domElement = listNode.item(0).toElement();
                childDS.m_pDomDocument = m_pDomDocument;
			}
		}

		return childDS;
	}

	/** @fn    QString CGenericDS::GetName() const
	  * @brief ��ȡ�ڵ�����
	  * @param <IN> none.
	  * @return QString - �ڵ�����.
	  */
	QString CGenericDS::GetName() const
	{
		return m_domElement.nodeName();
	}

	/** @fn    bool CGenericDS::CreateASRoot(const QString& strName)
	  * @brief ����root�ڵ�
	  * @param <IN> const QString& strName - �ڵ���.
	  * @return bool - true -�����ɹ� false - ʧ��.
	  */
	bool CGenericDS::CreateASRoot(const QString& strName)
	{
		QString strHead("version=\"1.0\" encoding=\"GB2312\"");
		m_pDomDocument.appendChild(m_pDomDocument.createProcessingInstruction("xml", strHead));

		m_domElement = m_pDomDocument.createElement(strName);
		m_pDomDocument.appendChild(m_domElement);

		return true;
	}

	/** @fn    CGenericDS CGenericDS::CreateChild(const QString& strName)
	  * @brief �����ӽڵ�
	  * @param <IN> const QString& strName - �ڵ���.
	  * @return bool - true -�����ɹ� false - ʧ��.
	  */
	CGenericDS CGenericDS::CreateChild(const QString& strName)
	{
		CGenericDS childDS;
        childDS.m_pDomDocument = m_pDomDocument;
		if(m_domElement.isNull())
		{
			return childDS;
		}

        childDS.m_domElement = m_pDomDocument.createElement(strName);
        m_domElement.appendChild(childDS.m_domElement);

		return childDS;
	}

    /** @fn bool iVMSGUIToolkit::CGenericDS::RemoveChild(const QString& strName)
     *  @brief ɾ���ӽڵ�
     *  @param (IN)const QString & strName �ڵ���
     *  @return true:ɾ���ɹ�,false:ɾ��ʧ��
     */
    bool CGenericDS::RemoveChild(const QString& strName)
    {
        if(m_domElement.hasChildNodes())
        {
            QDomNodeList listNode = m_domElement.elementsByTagName(strName);
            if (listNode.count() > 0)
            {
                m_domElement.removeChild(listNode.at(0));
            }
        }

        return true;
    }

    /** @fn bool iVMSGUIToolkit::CGenericDS::RemoveChild(int iIndex)
     *  @brief ɾ���ӽڵ�
     *  @param (IN)int iIndex �ӽڵ�����
     *  @return true:ɾ���ɹ�,false:ɾ��ʧ��
     */
    bool CGenericDS::RemoveChild(int iIndex)
    {
        int iEleNum = 0;
        if(m_domElement.hasChildNodes())
        {
            for (QDomNode domNode = m_domElement.firstChild(); !domNode.isNull(); domNode = domNode.nextSibling())
            {
                if(domNode.isElement())
                {
                    if(iEleNum == iIndex)
                    {
                        m_domElement.removeChild(domNode);

                        return true;
                    }

                    ++iEleNum;
                }
            }
        }

        return false;
    }

	/** @fn    bool CGenericDS::SetValue(const QString& strValue)
	  * @brief ���ýڵ�ֵ
	  * @param <IN> const QString& strValue - �ڵ�ֵ.
	  * @return bool - true - ���óɹ� false - ʧ��.
	  */
	bool CGenericDS::SetValue(const QString& strValue) //set value  no  unicode
	{
		if(m_domElement.isNull())
		{
			return false;
		}

		if(m_domElement.hasChildNodes())
		{
			for (QDomNode node = m_domElement.firstChild(); !node.isNull(); node = node.nextSibling())
			{
				if(node.isText())
				{
					node.toText().setData(strValue);
					return true;
				}
			}
		}

		QDomNode domNode = m_pDomDocument.createTextNode(strValue);
		m_domElement.appendChild(domNode);

		return true;
	}

	/** @fn    bool CGenericDS::SetAttribute(const QString& strName, const QString& strValue)
	  * @brief ���ýڵ�ֵ
	  * @param <IN> std::string strName - �ڵ���.
	  * @param <IN> std::string strValue - �ڵ�ֵ.
	  * @return bool - true - ���óɹ� false - ʧ��.
	  */
	bool CGenericDS::SetAttribute(const QString& strName, const QString& strValue)
	{
		if(m_domElement.isNull())
		{
			return false;
		}

		m_domElement.setAttribute(strName, strValue);
		return true;
	}

	/** @fn    bool CGenericDS::GetValue(QString& strValue) const
	  * @brief ��ȡ�ڵ�ֵ
	  * @param <IN> QString& strValue - �ڵ�ֵ.
	  * @return bool - ��ȡ�ɹ�.
	  */
	bool CGenericDS::GetValue(QString& strValue) const
	{
		if(m_domElement.hasChildNodes())
		{
			for (QDomNode domNode = m_domElement.firstChild(); !domNode.isNull(); domNode = domNode.nextSibling())
			{
				if(domNode.isText())
				{
                    strValue = domNode.toText().data();
					return true;
				}
			}
		}

		return false;
	}

    /** @fn    QString CGenericDS::GetValue() const
      * @brief �ṩ�˽ӿڿ�ֱ�ӻ�ȡֵ
      * @param <IN> none.
      * @return QString& strValue - �ڵ�ֵ.
      */
    QString CGenericDS::GetValue() const
    {
        QString strValue;
        GetValue(strValue);
        return strValue;
    }

    /** @fn    QString CGenericDS::GetAttribute(const QString& strKeyName) const
	  * @brief ��ȡ�ڵ���ΪstrName��ֵ
	  * @param <IN> const QString& strKeyName   - �ڵ���.
	  * @param <IN> const QString& strDefValue - ����ȡ���������ش�Ĭ��ֵ.
	  * @return �ڵ��Ӧ��ֵ.
	  */
	QString CGenericDS::GetAttribute(const QString& strKeyName, const QString& strDefValue) const
	{
		return m_domElement.attribute(strKeyName, strDefValue);
	}
}
