/*
 ���дʹ��˹���
 ���д��ı��У�һ�д���һ�����д�
*/

#pragma once

#include <map>
#include <string>

static const int MAX_SENSITIVEWORD_SIZE = 127;				// ���д�����ֽ���

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