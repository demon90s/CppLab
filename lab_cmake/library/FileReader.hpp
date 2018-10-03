#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

class FileReader
{
public:
	FileReader() : m_length(0), m_data(0) {}
	~FileReader()
	{
		if (m_data) free(m_data);
	}

	bool Load(const char *filename)
	{
		FILE *fp = fopen(filename, "rb");
		if (!fp) return false;

		// Get the file size, so we can pre-allocate the memory. HUGE speed impact.
		long length = 0;
		fseek(fp, 0, SEEK_END);
		length = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		m_data = (char*)malloc(length + 1);
		memset(m_data, 0, length + 1);
		fread(m_data, length, 1, fp);

		m_length = length;

		fclose(fp);

		return true;
	}

	char *Data()
	{
		return m_data;
	}

	const char *Data() const
	{
		return m_data;
	}

	long Length() const
	{
		return m_length;
	}

private:
	long m_length;
	char *m_data;
};