# Ryan Grayson
# rtg5xkh
# Inlab 11
# Makefile
# 5/1/2021

CXX = clang++
CXXFLAGS = -O2

OFILES = middleearth.o traveling.o

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

.PHONY: clean

clean:
	/bin/rm -f *.o *~ a.out

middleearth.o: middleearth.cpp middleearth.h
traveling.o: traveling.cpp middleearth.h