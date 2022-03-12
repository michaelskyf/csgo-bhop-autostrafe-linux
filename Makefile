LIBNAME := libcheat.so
CFLAGS := -Ofast -fPIC -shared -march=native -ldl -pthread
LDFLAGS := -Wl,--no-undefined
MISCFLAGS := -Wall -Wundef -Wno-unused-parameter

CC = /bin/cc

sources := $(shell find . -iname "*.c")

all:
	$(CC) -o $(LIBNAME) $(sources) $(MISCFLAGS) $(CFLAGS) $(LDFLAGS)
