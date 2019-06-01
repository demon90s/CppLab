// example: 链接指示，extern "C"
// extern 是一个链接指示，指示内容为非C++的语法
// extern "C" 表示后续的内容是C语言语法
// __cplusplus 宏属于c++编译器，如果用它来链接C语言实现的函数，就必须加上链接指示，生成正确的符号

// 否则，会提示错误，比如 undefined reference to ...

#include <cstdio>

using namespace std;

#ifdef __cplusplus
extern "C"
#endif 
int strlen_custom(const char *str);

int main()
{
	printf("%d\n", strlen_custom("Hello World"));

	return 0;
}
