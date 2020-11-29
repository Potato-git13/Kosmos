CFLAGS=-g -Wall -Wextra -pedantic -Wformat=2

# Compiles and generates src/pass and bin if needed
all: c src/pass

# Generates the src dir and pass file if needed.
src/pass:
	echo Password >src/pass

# Compiles and makes bin if needed
c: src/main.c src/help.c src/access.c
	mkdir -p bin
	$(CC) -o bin/main src/main.c src/help.c src/access.c -lm

# run
r: all
	bin/main

# compile and run
cr: all r

# run with a debugger
rd: all
	gdb bin/main

# compile and run with a debugger
crd: all rd

# Tell makefile that those arguments aren't files
.PHONY: all c r cr rd crd
