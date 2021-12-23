# Ryan Grayson
# rtg5xkh
# PostLab 6
# 3/30/2021
# Makefile

CXX = clang++
CXXFLAGS = -O2

OFILES = timer.o hashTable.o wordPuzzle.o

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

.PHONY: clean

clean:
	/bin/rm -f *.o *~ a.out

timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
hashTable.o: hashTable.cpp hashTable.h