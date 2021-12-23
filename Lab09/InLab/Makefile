# Ryan Grayson
# rtg5xkh
# InLab 9
# Makefile
# 4/18/2021

CXX = clang
CXXFLAGS = -fsanitize=address -fno-omit-frame-pointer -Wall -g

OFILES = linkedlist.o

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

.PHONY: clean

clean:
	/bin/rm -f *.o *~ a.out
