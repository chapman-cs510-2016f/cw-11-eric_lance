# This is a Makefile
# It automates build tasks for C (and other languages) easily

# Tell make that the targets test and clean are abstract (not actual files)
.PHONY : test clean

# Sets default compiler options
export CC = gcc
export CFLAGS = -Wall -O2 -I../src/stack -I../src/matrix
# Change to flags below for debugging with gdb
#export CFLAGS = -Wall -O0 -g

# Default target: this is executed if nothing else is specified
# As written, this descends into subdirectories src and test
# and executes "make" in those directories, respectively
all:
	mkdir -p bin
	$(MAKE) -C src/
	$(MAKE) -C test/

# test target: this is executed upon a "make test"
test: 
	$(MAKE) -C test/ test

# clean target: this is executed upon a "make clean"
clean:
	$(MAKE) -C src/ clean
	$(MAKE) -C test/ clean

cleaner: clean
	rm -f bin/*
	$(MAKE) -C test/ cleaner
