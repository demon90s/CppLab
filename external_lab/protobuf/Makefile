CC=g++
INCLUDE=-I/usr/local/include
CPPFLAGS=-g -Wall -std=c++11
LDFLAGS=-g -Wall -pthread -L/usr/local/lib -lprotobuf -lpthread

COMPILE_PROTO=protoc --cpp_out=. hello.proto

all: reader writer

reader: reader.o hello.pb.o
writer: writer.o hello.pb.o

hello.pb.h: hello.proto
	$(COMPILE_PROTO)

hello.pb.cc: hello.proto
	$(COMPILE_PROTO)

###########################################
# auto gen by gcc -MM
hello.pb.o: hello.pb.cc hello.pb.h
reader.o: reader.cpp common.h hello.pb.h
writer.o: writer.cpp common.h hello.pb.h
###########################################

clean:
	rm -f *.o *.pb* writer reader log
