CC = g++
INCLUDE = /usr/include/google
CPPFLAGS = -g -Wall -std=c++11
LDFLAGS = -L/usr/lib/google -lpthread -lgtest

TARGETS = stoi_stol_stoul_stof \
	string-append \
	string-assign \
	string-compare \
	string-construct \
	string-copy \
	string-erase \
	string-find_first_not_of \
	string-find_first_of \
	string-find_last_not_of \
	string-find_last_of \
	string-find \
	string-insert \
	string-replace \
	string-rfind \
	string-substr \
	to_string \

all: $(TARGETS)

%: %.cpp
	@$(CC) $(CPPFLAGS) -I$(INCLUDE) -o $@ $< $(LDFLAGS)
	@echo "[BUILT] $@"

clean:
	-rm -f $(TARGETS)
