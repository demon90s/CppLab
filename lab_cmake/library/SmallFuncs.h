#ifndef SMALL_FUNCS_H
#define SMALL_FUNCS_H

// ������̣�����ѡ�����һ���ַ�����Ϊ��ʾ
extern void Pause(const char *notice = nullptr);

// �ж� Buffer �Ƿ��� UTF8 ��ʽ������
extern bool IsUTF8(const char* buffer, long size);

// �ж� Buffer �Ƿ��� UTF8 �� BOM ��ʽ������
extern bool IsUTF8_Bom(const char* buffer, long size);

// �ж��ļ��Ƿ��� UTF-8 �� BOM ��ʽ��
extern bool Is_File_UTF8_NoBom(const char *filename);

#endif // SMALL_FUNCS_H