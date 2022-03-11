LIBNAME := libcheat.so
CFLAGS := -Ofast -fPIC -shared -march=native -ldl -pthread
MISCFLAGS := -Wall

CC = /bin/cc

sources := $(shell find . -iname "*.c")

all:
	$(CC) -o $(LIBNAME) $(sources) $(MISCFLAGS) $(CFLAGS)
