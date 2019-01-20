# -H 的作用是显示源文件是否使用了预编译头，在编译时，在行首输出！即使用了预编译头
CXXFLAGS=-H -g -Wall -std=c++11

OBJS=main.o src1.o src2.o src3.o src4.o src5.o src6.o src7.o src8.o src9.o src10.o

main: stdafx.h.gch ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

# 生成预编译头文件
stdafx.h.gch: stdafx.h
	@echo "Gernerating precompile header"
	g++ -g -Wall -std=c++11 stdafx.h

main.o: main.cpp stdafx.h stdafx.h
src10.o: src10.cpp stdafx.h stdafx.h
src1.o: src1.cpp stdafx.h stdafx.h
src2.o: src2.cpp stdafx.h stdafx.h
src3.o: src3.cpp stdafx.h stdafx.h
src4.o: src4.cpp stdafx.h stdafx.h
src5.o: src5.cpp stdafx.h stdafx.h
src6.o: src6.cpp stdafx.h stdafx.h
src7.o: src7.cpp stdafx.h stdafx.h
src8.o: src8.cpp stdafx.h stdafx.h
src9.o: src9.cpp stdafx.h stdafx.h

clean:
	rm -f *.o *.gch main
