SRCS = $(wildcard *.cc)

all : $(SRCS:.cc=)

# NOTE - unneeded, works without
.cc:
	g++ -std=c++11 $(CPFLAGS) $< -o $@
