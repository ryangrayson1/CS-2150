# Ryan Grayson
# rtg5xkh
# InLab 5
# 3/20/2021
# Makefile

CXX = clang++
CXXFLAGS = -Wall -O2
DEBUG = -g

OFILES = BinaryNode.o BinarySearchTree.o BSTPathTest.o

.PHONY: clean

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES)

clean:
	/bin/rm -f *.o *~ a.out

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h