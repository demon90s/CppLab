#ifndef SMALL_FUNCS_H
#define SMALL_FUNCS_H

// 挂起进程，可以选择输出一个字符串作为提示
extern void Pause(const char *notice = nullptr);

// 判断 Buffer 是否是 UTF8 格式的序列
extern bool IsUTF8(const char* buffer, long size);

// 判断 Buffer 是否是 UTF8 带 BOM 格式的序列
extern bool IsUTF8_Bom(const char* buffer, long size);

// 判断文件是否是 UTF-8 无 BOM 格式的
extern bool Is_File_UTF8_NoBom(const char *filename);

#endif // SMALL_FUNCS_H