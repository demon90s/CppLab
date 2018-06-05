# 概述

cmake可以用来生成项目工程文件，比如Linux下的Makefile文件，VS下的sln等文件。cmake使用一个名为CMakeLists.txt的文件来描述项目构建过程。

使用cmake构建一个项目的流程如下：

1. 编写CMakeLists.txt文件

2. 执行`cmake <path>`生成工程文件，path目录下存放着CMakeLists.txt文件

3. 编译项目，比如Linux下可使用make命令

# 安装与使用

CentOS 7安装命令：

```shell
$ yum install cmake
$ cmake --version
```

Windows下直接下载安装包即可：https://cmake.org/download/

**构建项目**

下面以Linux平台为例。

使用方法为：

```shell
$ cmake path
$ make
```

使用path目录下的CMakeLists.txt来生成Makefile文件，生成的Makefile文件位于当前cmake命令执行目录。

cmake命令还会在命令执行目录生成一些中间文件。

**清理项目**

只需输入：

```shell
$ make clean
```

但不会清理cmake生成的中间文件。

**外部构建**

cmake除了会在命令执行目录生成MakeFile文件，还会生成许多一些中间文件，因此最好是把它们统一放到一个目录中，在此目录执行cmake，这就是外部构建。

例如，可在项目目录下创建一个build目录，作为cmake命令的执行目录，CMakeLists.txt文件放在项目目录下，然后这样构建项目：

```
$ cd build
$ cmake ..
$ make
```

这样，想要删除cmake生成的中间文件时，直接执行`rm -rf build`即可。

**生成Debug或Release版本的程序**

```
$ cmake -DCMAKE_BUILD_TYPE=Debug path
```

这里设置了变量CMAKE_BUILD_TYPE的值为Debug，表示生成的是D ebug版本的程序。还可以取值为Release。

# 编写CMakeLists.txt

## 语法

CMakeLists.txt语法由指令、变量、注释组成。

**指令**

指令由指令名、小括号、参数组成。参数以空格分隔。

**变量**

变量分为内置的和自定义的。

引用变量的方法是：${变量名}。

变量是全局的，在上层CMakeLists.txt定义的变量，在下层可以使用。

**注释**

`#`符号后面的内容被认为是注释

## 指令

**CMAKE_MINIMUM_REQUIRED**

限定cmake的版本，如果当前cmake版本低，则生成失败。通常它位于顶层CMakeLists.txt的第一行。

使用例子：

```shell
CMAKE_MINIMUM_REQUIRED(VERSION 2.0)
```

---

**PROJECT**

定义项目的名称。

使用例子：

```shell
PROJECT(projectname)
```

一旦使用了此指令，将定义两个变量：`projectname_BINARY_DIR`和`projectname_SOURCE_DIR`，这两个变量与这两个内置变量是等价：`PROJECT_BINARY_DIR`和`PROJECT_SOURCE_DIR`

---

**MESSAGE**

发送一段信息文本到标准输出。

使用例子：

```shell
MESSAGE("cmake start")
```

---

**SET**

自定义一个变量，或者改变内置变量的值。

指令语法：

```shell
SET(VAR [VALUE])
```

使用例子：

```shell
SET(SRC_LIST main.c t1.c t2.c)
```

---

---

**INCLUDE_DIRECTORIES**

设置头文件包含目录。

使用例子：

```shell
INCLUDE_DIRECTORIES(. ./src) # 目录列表
```

---

**ADD_SUBDIRECTORY**

指明本工程中还有一个子目录，当执行到此指令时，会进入到子目录中，使用子目录中的CMakeList进行构建。

使用例子：

```shell
ADD_SUBDIRECTORY(src)
```

---

**FILE**

文件相关的操作。支持通配符扩展。

使用例子：

```shell
FILE(GLOB_RECURSE SRC_FILES *.cpp) # 获取当前处理的CMakeLists.txt文件所在目录及其子目录中所有的cpp文件，放到SRC_FILES变量里
```

GLOB_RECURSE代表全局递归查找。

---

**ADD_EXECUTABLE**

设置生成一个可执行文件。通常位于次级CMakeLists.txt。

指令语法：

```shell
ADD_EXECUTABLE(exefile src_file_list)
```

使用例子：

```shell
ADD_EXECUTABLE(main main.c t1.c t2.c)
```

---

**ADD_LIBRARY**

设置生成一个库文件。

指令语法：

```shell
ADD_LIBRARY(libname [SHARED | STATIC] source_list)
```

说明：

- libname无需加lib前缀和.so后缀
- SHARED表示动态库，STATIC表示静态库，默认是静态库

---

**LINK_DIRECTORIES和TARGET_LINK_LIBRARIES**

设置链接库的所在目录，设置目标所需要的链接库文件。

指令语法：

```shell
LINK_DIRECTORIES(dir_list)
TARGET_LINK_LIBRARIES(target lib_list)
```

注：

- 如果是共享库，可以不写前缀与后缀；如果是静态库，要写全名

- TARGET_LINK_LIBRARIES命令要写在ADD_EXECUTABLE后面

---

**STRING**

可以修改字符串，将其存到一个变量里。此变量可以事先没有SET。

指令语法：

```shell
STRING([TOLOWER | TOUPPER] string output_val) # 将string转换成小写，赋给output_val
```

使用例子：

```shell
STRING(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
```

---

## 内置变量

**PROJECT_BINARY_DIR与PROJECT_SOURCE_DIR**

项目的可执行文件目录与源文件目录（最后面没有/）。

PROJECT_BINARY_DIR默认值是编译（make）发生的当前目录。

PROJECT_SOURCE_DIR是工程的顶层目录（顶层CMakeLists.txt所在目录）。

---

**EXECUTABLE_OUTPUT_PATH与LIBRARY_OUTPUT_PATH**

最终的目标二进制位置；最终的共享库位置。都不包含中间文件。

通常用SET命令设置，如：

```shell
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
```

---

**CMAKE_CXX_FLAGS**

C++编译选项。

另外还有：

- CMAKE_CXX_FLAGS_DEBUG，当CMAKE_BUILD_TYPE为Debug时启用
- CMAKE_CXX_FLAGS_RELEASE，当CMAKE_BUILD_TYPE为Release时启用

---

**CMAKE_CURRENT_SOURCE_DIR**

当前处理的CMakeLists.txt所在路径。

---

# 例子

```
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(proc)

INCLUDE_DIRECTORIES(.)

SET(CMAKE_CXX_FLAGS "-g -Wall")

FILE(GLOB_RECURSE SRC_FILES "./src/*.cpp")

SET(EXECUTABLE_OUTPUT_PATH .)
ADD_EXECUTABLE(proc ${SRC_FILES})
```

# 参考资料

[在 linux 下使用 CMake 构建应用程序](https://www.ibm.com/developerworks/cn/linux/l-cn-cmake/index.html)