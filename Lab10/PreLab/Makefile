# Ryan Grayson
# rtg5xkh
# PreLab 10
# Makefile
# 4/21/2021

CXX = clang++
CXXFLAGS = -fsanitize=address -fno-omit-frame-pointer -Wall -g

OFILES = huffnode.o heap.o huffmanenc.o

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

.PHONY: clean

clean:
	/bin/rm -f *.o *~ a.out

heap.o: heap.cpp heap.h huffnode.h
huffmanenc.o: huffmanenc.cpp heap.h huffnode.h
huffnode.o: huffnode.cpp huffnode.h