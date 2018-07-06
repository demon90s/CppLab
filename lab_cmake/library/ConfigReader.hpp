#ifndef __CONFIG_READER_HPP__
#define __CONFIG_READER_HPP__

#include <bitset>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

// 简单地读取配置的工具

/*
 读取这样的节点：
 <root_node>
	<data>
		<seq>0</seq>
	</data>
	<data>
		<seq>1</seq>
	</data>
 </root_node>
*/

typedef rapidxml::xml_document<> XmlDoc;
typedef rapidxml::file<> XmlFile;
typedef rapidxml::xml_node<> XmlNode;

template<typename T, size_t LEN>
class ConfigItemList
{
public:
	ConfigItemList(XmlNode* root_node) : m_root_node(root_node) {}

	bool ReadConfigList()
	{
		T tmp_cfg_item;
		for (auto cur_node = m_root_node->first_node("data"); cur_node; cur_node->next_sibling())
		{
			if (!tmp_cfg_item.Read(cur_node)) return false;
			
			int index = tmp_cfg_item.GetIndex();
			if (index < 0 || index >= LEN) return false;

			m_config_item_list[index] = tmp_cfg_item;
			m_read_flag.set(index);
		}
		return true;
	}

	const T* GetConfigItem(int index) const
	{
		if (!IsValidIndex(index)) return nullptr;
		return m_config_item_list[index];
	}

private:
	static bool IsValidIndex(int index)
	{
		return index >= 0 && index < LEN && m_read_flag.test(index);
	}

	T m_config_item_list[LEN];
	std::bitset<LEN> m_read_flag;
	XmlNode* const m_root_node;
};

#endif // __CONFIG_READER_HPP__