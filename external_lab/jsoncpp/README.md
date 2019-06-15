jsconcpp version: 1.8.4

https://github.com/open-source-parsers/jsoncpp/tree/1.8.4

install by cmake:

```
mkdir -p build/debug
cd build/debug
cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_STATIC_LIBS=ON -DBUILD_SHARED_LIBS=OFF -DARCHIVE_INSTALL_DIR=. -G "Unix Makefiles" ../..
make
```
