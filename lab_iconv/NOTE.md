# 说明

iconv是一个计算机程序以及一套应用程序编程接口的名称。它的作用是在多种国际编码格式之间进行文本内码的转换。

# iconv函数族

<details>

<summary>View details</summary>

```
#include <iconv.h>

iconv_t iconv_open(const char *tocode, const char *fromcode);
int iconv_close(iconv_t cd);

size_t iconv(iconv_t cd,
             char **inbuf, size_t *inbytesleft,
             char **outbuf, size_t *outbytesleft);
```

在Linux平台，libiconv已经包含在C运行时库libc.so中，因此可以直接使用上述接口。

**iconv_open**函数分配一个转换说明符（conversion descriptor），用于字符集的转换。

tocode是要转换到的字符编码（character encoding），fromcode是从哪种字符编码转换。tocode和fromcode都是依赖于系统的，在Linux平台下，可以使用`iconv --list`查看支持的字符编码。

函数返回的转换说明符可以一直被iconv使用，直到调用了iconv_close被释放为止。如果出现错误，会设置errno，并返回(iconv_t)-1。

转换说明符包含了一个转换状态（conversion state），当使用iconv_open创建完毕后，转换状态处于初始状态。iconv函数会修改转换状态。

**iconv_close**函数释放转换说明符。这个转换说明符是之前由iconv_open分配的。

如果成功，函数返回0，出现错误，会设置errno，并返回-1。

**iconv**函数将一种字符编码的字符序列（sequence of characters）转换成另一种字符编码的字符序列。

cd参数是转换描述符，由iconv_open函数创建，它描述了要转换的字符编码。

inbuf参数指向了输入字符序列的第一个字符的地址。inbytesleft代表inbuf的字节数。

outbuf参数指向了输出buffer的第一个可用字节的地址。outbyteleft代表了输出buffer的可用字节数。

当inbuf和\*inbuf不为NULL时，iconv函数把inbuf中的字符序列转换到outbuf中。其中，inbuf最多读取\*inbytesleft个字节，outbuf最多写\*outbytesleft个字节。

iconv函数一次转换一个多字节字符，每次转换它都会增长\*inbuf和\*outbuf并减少\*inbytesleft和\*outbytesleft。它还会更新转换标识符中的转换状态。

如果inbuf或者\*inbuf是NULL，并且outbuf或者\*outbuf是NULL，iconv函数把转换描述符的转换状态设为初始值。

**返回值**：函数返回转换的字符数量。如果出现错误，会设置errno，并返回(size_t)-1。

</details>

# 参考资料

man 3 iconv

[iconv - 维基百科](https://zh.wikipedia.org/wiki/Iconv)
