LIBS=-pthread -L/usr/local/lib -lprotobuf -lpthread
INCLUDE=-I/usr/local/include
FLAGS=-g -Wall -std=c++11

COMPILE_PROTO=protoc --cpp_out=. hello.proto

start:
	$(COMPILE_PROTO)
	g++ $(FLAGS) -o writer writer.cpp hello.pb.cc $(LIBS) $(INCLUDE)
	g++ $(FLAGS) -o reader reader.cpp hello.pb.cc $(LIBS) $(INCLUDE)

clean:
	rm -f *.o *.pb* writer reader log
