#ifndef XML_READER_H
#define XML_READER_H

#include <memory>
#include <vector>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

// 测试用例
extern void Test_XmlReader_GetValue1();
extern void Test_XmlReader_GetValue2();

// 封装RapidXml，简化读取配置的操作
class XmlReader
{
	typedef rapidxml::xml_document<> XmlDoc;
	typedef rapidxml::file<> XmlFile;
public:
	XmlReader(const char *file_name);

	/*
	 * 根据xml的路径获取值："config/name"
	 * <config>
	 *     <name>Liudiwen</name>
	 * </config>
	 */
	const char *GetValue(const char *xml_path) const;

	/*
	 * 根据xml的路径，获取最后一个节点兄弟的值: "config/reading/data"
	 * <config>
	 *     <reading>
	 *         <data>CppPrimer</data>
	 *         <data>Linux Programming</data>
	 *     </reading>
	 * </config>
	 */
	bool GetValue(const char *xml_path, std::vector<const char*> &value_list) const;

private:
	XmlDoc m_doc;
	std::unique_ptr<XmlFile> m_file;
	bool m_parsed = false;
};

#endif XML_READER_H // XML_READER_H