#! /bin/bash

GTEST_FILE="googletest-release-1.8.1"

f_log()
{
	echo "==> $1 <=="
}

f_log "install unzip"

sudo apt install -y unzip

f_log "unzip google-test source file"

unzip ${GTEST_FILE}.zip

f_log "build libgtest.a"

GTEST_DIR=./${GTEST_FILE}/googletest
g++ -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
ar -rv libgtest.a gtest-all.o

mv libgtest.a ./lib
rm -f gtest-all.o

f_log "delete google-test source file"

rm -fr ${GTEST_FILE}

ls ./lib
