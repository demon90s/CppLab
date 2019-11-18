/*
 敏感词过滤工具
 敏感词文本中，一行代表一个敏感词
*/

#pragma once

#include <map>
#include <string>

static const int MAX_SENSITIVEWORD_SIZE = 127;				// 敏感词最大字节数

class NameNode;

class NameFilter
{
public:
	static NameFilter & Instance();

	bool Init(const char *filename, std::string *err);

	void AddSensitiveWord(int max_len, const char *word);
	bool HasSensitiveWord(int max_len, const char *input_word);

private:
	NameFilter();
	~NameFilter();
	NameFilter(const NameFilter&) = delete;
	NameFilter& operator=(const NameFilter&) = delete;

	NameNode *m_root;
};