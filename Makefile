#!/bin/bash
#***************************************************************************************************
# Makefile
#***************************************************************************************************

# The name of the executable file (called a binary).
BINARY = tempc

# Options for the C compiler.
CFLAGS = -ansi -c -g -O0 -Wall

# a list of the .c files in the project.
SOURCES = CtoF.c    \
          CtoK.c    \
          FtoC.c    \
          FtoK.c    \
          Main.c

# A list of the .o files in the project. Replaces all occurrences of .c in the SOURCES macro with
# .o, i.e., OBJECTS will be assigned: CtoF.o, FtoC.o, and Main.o.
OBJECTS = $(SOURCES:.c=.o)

# A list of the .d dependency files in the project.
DEPS = $(SOURCES:.c=.d)

# The binary depends on the object files. Link the object files to produce the binary.
$(BINARY): $(OBJECTS)
	gcc $(OBJECTS) -o $(BINARY)

# Even though there is an implicit rule which states that the .o files depend on the. c files, I
# like to be explicit about it. Compile a .c file to produce a .o file.
%.o: %.c
	gcc $(CFLAGS) $< -o $@

# The .d files depend on the .c files. Ccreate a .d file by running gcc –MM.
%.d: %.c
	rm -f $@; gcc -MM $< > $@

# Include the contents of all of the .d files.
include $(DEPS)

# "clean" is a phony target. Delete all of the .o and .d files and the binary.
.PHONY: clean
clean:
	rm -f $(OBJECTS)
	rm -f $(DEPS)
	rm -f $(BINARY)
