#include "SmallFuncs.h"
#include "marcofuncs.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#ifdef __unix
#include <unistd.h>
#include <sys/time.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

void Pause(const char *notice)
{
	if (notice)
	{
		std::cout << notice << std::flush;
	}
#ifdef __unix
	pause();
#endif

#ifdef _MSC_VER
	system("pause > nul");
#endif
}

unsigned long PITime()
{
#ifdef __unix
	struct timezone tz = { 0, 0 };
	timeval time;
	gettimeofday(&time, &tz);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
#elif defined(_WIN32)
	return GetTickCount();
#endif
}

void PISleep(unsigned long timems)
{
#ifdef __unix 	// usleep( time * 1000 );
	usleep((timems << 10) - (timems << 4) - (timems << 3));
#elif defined(_WIN32)
	Sleep(timems);
#endif
}

bool TimeStrToTimestamp(const char *time_str, time_t *timestamp)
{
	if (NULL == time_str || NULL == timestamp) return false;

	if (strlen(time_str) < 19) return false;

	char temp[256] = { 0 };
	strncpy(temp, time_str, sizeof(temp));

	struct tm local_tm;
	memset(&local_tm, 0, sizeof(local_tm));

	char *pt = &temp[0];

	pt[4] = '\0';
	local_tm.tm_year = atoi(pt) - 1900; if (local_tm.tm_year <= 70 || local_tm.tm_year > 200) return false;
	pt += 5;

	pt[2] = '\0';
	local_tm.tm_mon = atoi(pt) - 1; if (local_tm.tm_mon < 0 || local_tm.tm_mon > 11) return false;
	pt += 3;

	pt[2] = '\0';
	local_tm.tm_mday = atoi(pt); if (local_tm.tm_mday < 1 || local_tm.tm_mday > 31) return false;
	pt += 3;

	pt[2] = '\0';
	local_tm.tm_hour = atoi(pt); if (local_tm.tm_hour < 0 || local_tm.tm_hour > 23) return false;
	pt += 3;

	pt[2] = '\0';
	local_tm.tm_min = atoi(pt); if (local_tm.tm_min < 0 || local_tm.tm_min > 59) return false;
	pt += 3;

	pt[2] = '\0';
	local_tm.tm_sec = atoi(pt); if (local_tm.tm_sec < 0 || local_tm.tm_sec > 59) return false;
	pt += 3;

	*timestamp = mktime(&local_tm);

	return true;
}

long long ConvertParamToLongLong(int param_0, int param_1)
{
	union
	{
		long long ll_value;
		struct
		{
			int param_0;
			int param_1;
		};
	} union_param;

	union_param.param_0 = param_0;
	union_param.param_1 = param_1;

	return union_param.ll_value;
}

void ParseParamFromLongLong(long long key, int *param_0, int *param_1)
{
	union
	{
		long long ll_value;
		struct
		{
			int param_0;
			int param_1;
		};
	} union_param;

	union_param.ll_value = key;
	*param_0 = union_param.param_0;
	*param_1 = union_param.param_1;
}

int RandomNum(int beg, int end)
{
	if (beg > end)
	{
		int tmp_num = beg;
		beg = end;
		end = tmp_num;
	}

	int interval_num = end - beg;
	if (interval_num <= 0)
	{
		return 0;
	}

	if (interval_num < RAND_MAX)
	{
		return beg + (rand() % interval_num);
	}
	else
	{
		int rand_num = (rand() << 16) + rand(); // �������������һ��int����Ҫ���windows��rand���ֵֻ��2^15�����⣩
		if (rand_num < 0)
		{
			rand_num *= -1;
		}
		return beg + int(rand_num % interval_num);
	}
}

bool IsUTF8(const char* buffer, long size)
{
	bool is_utf8 = true;
	unsigned char* start = (unsigned char*)buffer;
	unsigned char* end = (unsigned char*)buffer + size;
	while (start < end)
	{
		if (*start < 0x80) // (10000000): ֵС��0x80��ΪASCII�ַ�   
		{
			start++;
		}
		else if (*start < (0xC0)) // (11000000): ֵ����0x80��0xC0֮���Ϊ��ЧUTF-8�ַ�   
		{
			is_utf8 = false;
			break;
		}
		else if (*start < (0xE0)) // (11100000): �˷�Χ��Ϊ2�ֽ�UTF-8�ַ�   
		{
			if (start >= end - 1)
				break;
			if ((start[1] & (0xC0)) != 0x80)
			{
				is_utf8 = false;
				break;
			}
			start += 2;
		}
		else if (*start < (0xF0)) // (11110000): �˷�Χ��Ϊ3�ֽ�UTF-8�ַ�   
		{
			if (start >= end - 2)
				break;
			if ((start[1] & (0xC0)) != 0x80 || (start[2] & (0xC0)) != 0x80)
			{
				is_utf8 = false;
				break;
			}
			start += 3;
		}
		else
		{
			is_utf8 = false;
			break;
		}
	}

	return is_utf8;
}

bool IsUTF8_Bom(const char* buffer, long size)
{
	if (!IsUTF8(buffer, size)) return false;

	if (static_cast<unsigned char>(buffer[0]) == 0xEF &&
		static_cast<unsigned char>(buffer[1]) == 0xBB &&
		static_cast<unsigned char>(buffer[2]) == 0xBF)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Is_File_UTF8_NoBom(const char *filename)
{
	std::ifstream ifs(filename);

	if (!ifs)
	{
		printf("open file failed\n");
		return false;
	}

	std::string file;
	std::string line;
	while (std::getline(ifs, line))
	{
		file += line;
		file += '\n';
	}

	bool is_utf8_no_bom = IsUTF8(file.c_str(), file.length()) && !IsUTF8_Bom(file.c_str(), file.length());

	return is_utf8_no_bom;
}
int ParseParam(const char *src, std::vector<std::string> &result, const char *delim)
{
	static char temp[4096] = {};

	STRNCPY(temp, src, sizeof(temp));
	result.clear();

	char *token = strtok(temp, delim);

	while (NULL != token)
	{
		result.push_back(token);
		token = strtok(NULL, delim);
	}

	return (int)result.size();
}

std::vector<std::string> SplitString(const std::string &str, const char *delim)
{
	std::vector<std::string> result;
	size_t delim_len = strlen(delim);
	std::string::size_type pos1 = 0;
	std::string::size_type pos2 = str.find(delim);

	while (pos2 != std::string::npos)
	{
		result.push_back(std::string(str, pos1, pos2 - pos1));

		pos1 = pos2 + delim_len;
		pos2 = str.find(delim, pos1);
	}

	if (pos1 != str.length())
	{
		result.push_back(std::string(str, pos1));
	}

	return result;
}

std::string StringFormat(const char *fmt, ...)
{
	int buffer_len = 1024;
	char *buffer = new char[buffer_len]{};
	int str_len = -1;

	do
	{
		va_list ap;
		va_start(ap, fmt);
		str_len = vsnprintf(buffer, buffer_len, fmt, ap);

		if (str_len >= buffer_len) {
			str_len = -1;

			char *tmp_buffer = new char[buffer_len * 2]{};
			delete[] buffer;
			buffer_len *= 2;
			buffer = tmp_buffer;
		}
		va_end(ap);
	} while (str_len == -1);

	std::string str = buffer;
	delete[] buffer;

	return str;
}