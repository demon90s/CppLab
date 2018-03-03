# 什么是RapidXml

RapidXml是一个用C++写的in-situ xml parser，速度很快。

所谓in-situ意思是它不会拷贝字符串，而只是保存字符串的指针，字符串资源保存在source text中。因此要求document object销毁前，source text还存在。source text就是读入的xml文档。

RapidXml只有header file，因此没有building和linking的必要，只需要引入其头文件即可。

RapidXml使用异常来报告错误。

# 测试代码

[test_rapidxml](./lab_rapidxml/test_rapidxml.cpp)

# 参考资料

[manual](./lib/)