# Ryan Grayson
# rtg5xkh
# PreLab 5
# 3/19/2021
# Makefile

CXX = clang++
CXXFLAGS = -Wall -O2
DEBUG = -g

OFILES = TreeNode.o TreeCalc.o TreeCalcTest.o

.PHONY: clean

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OFILES)

clean:
	/bin/rm -f *.o *~ a.out

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
TreeNode.o: TreeNode.cpp TreeNode.h