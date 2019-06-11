google test version: 1.8.1

test platform: Ubuntu server 18.04 

###################
build lib step:

1. GTEST_DIR=/home/diwen/googletest-release-1.8.1/googletest

2. g++ -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR}     -pthread -c ${GTEST_DIR}/src/gtest-all.cc

3. ar -rv libgtest.a gtest-all.o
###################

primer doc: https://github.com/google/googletest/blob/master/googletest/docs/primer.md
