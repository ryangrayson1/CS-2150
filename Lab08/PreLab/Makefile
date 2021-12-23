# Ryan Grayson
# rtg5xkh
# PreLab 8
# 4/9/2021
# Makefile
# *Note: this is for macOS compilation. "macho64" needs to be changed to "elf64" for Linux

CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f macho64 -g

OBJECTS = mathlib.o mathfun.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~