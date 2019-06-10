## 准备工作

### 安装protobuf

先到package目录拿到压缩包解压。之后进入解压目录。

```
$ ./configure
$ make
$ make check
$ sudo make install
$ ldconfig # protobuf库默认安装到了：/usr/local/include，检查有没有加入到 /etc/ld.so.conf 文件
```

这个安装过程在我的虚拟机里比较久。

如果是windows平台，在包里有一个cmake目录，可以用cmake工程build。

### 安装pkg-config

先到package目录拿到压缩包解压，之后进入解压目录。


```shell
$ ./configure
$ make
$ make check
$ sudo make install
```

之后，就可以通过这个命令查看编译链接protobuf所需的命令：

```
$ pkg-config --cflags --libs protobuf
```

## .proto文件

首先需要编写一个proto文件，在protobuf术语中，结构化数据被称为Message。

参见 hello.proto。

编写好后，用这个命令生成c++的文件：

```
protoc --cpp_out=. hello.proto
```

## 使用protobuf

参见 writer.cpp 和 reader.cpp

## 参考资料

[Official site](https://developers.google.cn/protocol-buffers/)

[Git](https://github.com/google/protobuf)

[C++ Installation](https://github.com/google/protobuf/blob/master/src/README.md)

[Protobuf的使用](https://www.ibm.com/developerworks/cn/linux/l-cn-gpb/index.html)
