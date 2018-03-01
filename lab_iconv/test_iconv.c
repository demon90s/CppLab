#include <stdio.h>
#include <string.h>

#ifdef __unix
#include <iconv.h>
#endif

#ifdef _WIN32
#include "lib/iconv.h"
#endif

int code_convert(char *from_charset, char *to_charset,
				 char *inbuf, int inlen,
				 char *outbuf, int outlen)
{
	char **inbuf_p = &inbuf;
	char **outbuf_p = &outbuf;
	size_t inlen_tmp = inlen;
	size_t outlen_tmp = outlen;

	iconv_t cd = iconv_open(to_charset, from_charset);
	if (cd == (iconv_t)-1) return -1;

	do
	{
		memset(outbuf, 0, outlen_tmp);
		if (iconv(cd, inbuf_p, &inlen_tmp, outbuf_p, &outlen_tmp) == (size_t)-1) break;
	} while (0);

	iconv_close(cd);

	return 0;
}

int u2g(char *inbuf, int inlen, char *outbuf, int outlen)
{
	return code_convert("utf-8", "gb2312", inbuf, inlen, outbuf, outlen);
}

int g2u(char *inbuf, int inlen, char *outbuf, int outlen)
{
	return code_convert("gb2312", "utf-8", inbuf, inlen, outbuf, outlen);
}

//------------------------------------------------------------------------------------

// try: 
// linux>./a.out < test_g2u.txt
// win32>你好！win iconv

#define BUFF_LEN 256

int main()
{
	char outbuf[BUFF_LEN] = {0};
	char inbuf[BUFF_LEN] = {0};
	int ret = 0;

	fgets(inbuf, sizeof(inbuf), stdin);

	if (inbuf[strlen(inbuf) - 1] == '\n')
		inbuf[strlen(inbuf) - 1] = '\0';

	printf("in: %s\n", inbuf);

#ifdef _WIN32
	ret = u2g(inbuf, (int)strlen(inbuf), outbuf, (int)sizeof(outbuf));
#endif
	
#ifdef __unix
	ret = g2u(inbuf, (int)strlen(inbuf), outbuf, (int)sizeof(outbuf));
#endif
	
	if (0 != ret)
	{
		perror("g2u fail");
	}
	else
	{
		printf("out: %s\n", outbuf);
	}

#ifdef _WIN32
	system("pause");
#endif

	return 0;
}
