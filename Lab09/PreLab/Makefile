# Ryan Grayson
# rtg5xkh
# PreLab 9
# 4/14/2021
# Makefile
# *Note: this is for macOS compilation. "macho64" needs to be changed to "elf64" for Linux

CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f macho64 -g

OBJECTS = threexplusone.o threexinput.o timer.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~

threexinput.o: threexinput.cpp timer.h
timer.o: timer.cpp timer.h