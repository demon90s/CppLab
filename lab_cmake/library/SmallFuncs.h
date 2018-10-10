#ifndef SMALL_FUNCS_H
#define SMALL_FUNCS_H

#include <time.h>

// ������̣�����ѡ�����һ���ַ�����Ϊ��ʾ
extern void Pause(const char *notice = nullptr);

// ��ȡ����ʱ���
extern unsigned long PITime();

// ʱ���ַ�������ʽ�� 2018-09-16 10:12:08��ת����ʱ���
extern bool TimeStrToTimestamp(const char *time_str, time_t *timestamp);

// ����int��һ��long long֮���ת��
long long ConvertParamToLongLong(int param_0, int param_1);
void ParseParamFromLongLong(long long key, int *param_0, int *param_1);

// ȡ�������ֵ��ȡֵ��Χ��[beg, end)
int RandomNum(int beg, int end);

// �ж� Buffer �Ƿ��� UTF8 ��ʽ������
extern bool IsUTF8(const char* buffer, long size);

// �ж� Buffer �Ƿ��� UTF8 �� BOM ��ʽ������
extern bool IsUTF8_Bom(const char* buffer, long size);

// �ж��ļ��Ƿ��� UTF-8 �� BOM ��ʽ��
extern bool Is_File_UTF8_NoBom(const char *filename);

#endif // SMALL_FUNCS_H