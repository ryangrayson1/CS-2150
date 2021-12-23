# Ryan Grayson
# rtg5xkh
# PreLab 5
# 3/24/2021
# Makefile

CXX = clang++
CXXFLAGS = -Wall -O2 -g

OFILES = timer.o hashTable.o wordPuzzle.o

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

.PHONY: clean

clean:
	/bin/rm -f *.o *~ a.out

timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
hashTable.o: hashTable.cpp hashTable.h