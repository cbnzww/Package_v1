/*
 * @fileXML  GenericDS.cpp
 * @note  Hikvision Digital Technology Co., Ltd. All Rights Reserved 
 * @brief XML操作类
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
	//构造
	CGenericDS::CGenericDS(void)
	{
	}

	//析构
	CGenericDS::~CGenericDS(void)
	{
	}

	/** @fn    bool CGenericDS::LoadXML(const QString& strXMLName)
	  * @brief 导入XML文件
	  * @param <IN> const QString& strXMLName － XML文件
	  * @return bool ture - 导入成功  false - 导入失败.
	  */
	bool CGenericDS::LoadXML(const QString& strXMLName)
	{
        if (strXMLName.isNull())
        {
            return false;
        }

        //打开xml文件
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
	 *    @brief  解析xml文本
	 *    @param  (IN) const QString& strXMl -xml文本信息
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
	  * @brief 保存xml
	  * @param <IN> const QString& strXMLName － XML文件
	  * @return bool ture - 保存成功  false - 保存失败.
	  */
	bool CGenericDS::SaveXML(const QString& strXMLName)
	{
        QFile fileXML(strXMLName);
        if (!fileXML.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return false;
        }

        //获取文本流 设置编码GB2312
        QTextStream textStreamOut (&fileXML);
        QTextCodec* pCodec = QTextCodec::codecForName("GB2312");
        textStreamOut.setCodec(pCodec);

        m_pDomDocument.save(textStreamOut, 0);

        fileXML.close();

        return true;
	}

	/** @fn int CGenericDS::GetChildrenCount() const
	 *  @brief  获取子节点数量
	 *  @param (IN) none.
	 *  @return int 字节点数量
	 */ 
	int CGenericDS::GetChildrenCount() const
	{
		//无元素存在
		if(m_domElement.isNull())
		{
			return 0;
		}

        int iEleNum = 0;

		//存在节点
		if(m_domElement.hasChildNodes()) //return locEle.childNodes().count();速度不快
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
	 *  @brief  获取子节点 按照索引
	 *  @param (IN) iIndex - 第几个字节点.
	 *  @return CGenericDS 节点 
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
	  * @brief 获取子节点 按照名称
	  * @param <IN> const QString& strName - 名称.
	  * @return CGenericDS 节点 
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
	  * @brief 获取节点名称
	  * @param <IN> none.
	  * @return QString - 节点名称.
	  */
	QString CGenericDS::GetName() const
	{
		return m_domElement.nodeName();
	}

	/** @fn    bool CGenericDS::CreateASRoot(const QString& strName)
	  * @brief 创建root节点
	  * @param <IN> const QString& strName - 节点名.
	  * @return bool - true -创建成功 false - 失败.
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
	  * @brief 创建子节点
	  * @param <IN> const QString& strName - 节点名.
	  * @return bool - true -创建成功 false - 失败.
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
     *  @brief 删除子节点
     *  @param (IN)const QString & strName 节点名
     *  @return true:删除成功,false:删除失败
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
     *  @brief 删除子节点
     *  @param (IN)int iIndex 子节点索引
     *  @return true:删除成功,false:删除失败
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
	  * @brief 设置节点值
	  * @param <IN> const QString& strValue - 节点值.
	  * @return bool - true - 设置成功 false - 失败.
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
	  * @brief 设置节点值
	  * @param <IN> std::string strName - 节点名.
	  * @param <IN> std::string strValue - 节点值.
	  * @return bool - true - 设置成功 false - 失败.
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
	  * @brief 获取节点值
	  * @param <IN> QString& strValue - 节点值.
	  * @return bool - 获取成功.
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
      * @brief 提供此接口可直接获取值
      * @param <IN> none.
      * @return QString& strValue - 节点值.
      */
    QString CGenericDS::GetValue() const
    {
        QString strValue;
        GetValue(strValue);
        return strValue;
    }

    /** @fn    QString CGenericDS::GetAttribute(const QString& strKeyName) const
	  * @brief 获取节点名为strName的值
	  * @param <IN> const QString& strKeyName   - 节点名.
	  * @param <IN> const QString& strDefValue - 若获取不到，返回此默认值.
	  * @return 节点对应的值.
	  */
	QString CGenericDS::GetAttribute(const QString& strKeyName, const QString& strDefValue) const
	{
		return m_domElement.attribute(strKeyName, strDefValue);
	}
}
