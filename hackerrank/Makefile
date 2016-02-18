SRCS = $(wildcard *.cc)

all : $(SRCS:.cc=)

# NOTE - unneeded, works without
.cc:
	g++ $(CPFLAGS) $< -o $@
