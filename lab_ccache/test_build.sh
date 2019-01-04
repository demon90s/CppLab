#! /bin/bash

# 参考：https://www.ibm.com/developerworks/cn/linux/l-ccache.html?mhq=ccache&mhsrc=ibmsearch_a

# 清空 ccache 缓存：ccache -C
# 查看 ccache 状态：ccache -s

main()
{
	make clean
	make
}

time main
