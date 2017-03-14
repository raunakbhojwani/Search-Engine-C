# Makefile TEMPLATE for 'common' library
#   Builds and compiles all the files into a library.
#
# George Hito and Raunak Bhojwani, April 2016

DEPS = file.h word.h file.h index.c
OBJS = file.o web.o word.o index.o
LIB = common.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb
CC = gcc
MAKE = make

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB): $(OBJS)
	ar cr $@ $^


# add cleanup commands for other subdirectories
clean:
	rm -f *~
	rm -f *.o
	rm -f $(LIB)
