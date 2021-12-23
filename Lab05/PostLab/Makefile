# Ryan Grayson
# rtg5xkh
# PostLab 5
# 3/22/2021
# Makefile

CXX = clang++
CXXFLAGS = -Wall -O2
DEBUG = -g

OFILES = AVLNode.o AVLTree.o AVLPathTest.o

.PHONY: clean

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES)

clean:
	/bin/rm -f *.o *~ a.out

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h