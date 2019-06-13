使用预编译头将比较固定的header file一次性打包编译，可以大量节约编译时间。

msvc:

- 创建一个文件stdafx.h，里面包含那些header file。创建一个stdafx.cpp文件，仅包含stdafx.h。然后右键stdafx.cpp文件 -> Properties -> C/C++ -> precompiled Header，选择Precompiled Header为：Create(/Yc)

- 右击项目 -> Properties -> C/C++ -> precompiled Header，选择Precompiled Header为：Use(/Yu)

- 项目中所有的cpp文件开头都需要`#include "stdafx.h"`

linux && gcc:

- 创建一个文件stdafx.h，里面包含header file, 然后将其编译成stdafx.h.gch

- 项目中所有的cpp文件开头都需要`#include "stdafx.h"`