# Ryan Grayson
# rtg5xkh
# InLab 10
# Makefile
# 4/22/2021

CXX = clang++
CXXFLAGS = -fsanitize=address -fno-omit-frame-pointer -Wall -g

OFILES = huffnode.o huffmandec.o

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

.PHONY: clean

clean:
	/bin/rm -f *.o *~ a.out

huffmandec.o: huffmandec.cpp huffnode.h
huffnode.o: huffnode.cpp huffnode.h

