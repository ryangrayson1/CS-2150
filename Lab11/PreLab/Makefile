# Ryan Grayson
# rtg5xkh
# PreLab 11
# Makefile
# 4/28/2021

CXX = clang++

OFILES = topological.o middleearth.o

main: $(OFILES)
	$(CXX) $(OFILES)
	doxygen

.PHONY: clean

clean:
	/bin/rm -f *.o *~ a.out

middleearth.o: middleearth.cpp middleearth.h
topological.o: topological.cpp