CXX = g++
CPPFLAGS = -g -Wall -std=c++11

TARGETS = test_Array \
			test_FixLenStr \
			test_ObjFuncInvoker \
			test_FixLenRankList \
			test_FixLenSet \
			test_FormattedTable \
			test_TimeUtil \

all: $(TARGETS)

test_funcs: test_funcs.cpp ../library/SmallFuncs.cpp
	$(CXX) $(CPPFLAGS) test_funcs.cpp ../library/SmallFuncs.cpp -o $@

test_FormattedTable: test_FormattedTable.cpp ../library/FormattedTable.hpp
	$(CXX) $(CPPFLAGS) test_FormattedTable.cpp -o $@

clean:
	-rm -f $(TARGETS)
