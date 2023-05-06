CC = gcc -Wall -O3
X86 = -msse4.2 -mavx2
SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, %.o, $(SOURCES))

ifeq ($(OS), Windows_NT)
	RM = del /s >nul 2>&1
endif
ifeq ($(OS), Linux)
	RM = rm -f
endif

all: x86

x86:
	$(CC) $(X86) -c $(SOURCES)
	ar rcs bin/x86_64/libstdm.a $(OBJECTS)
	ranlib bin/x86_64/libstdm.a
	$(RM) $(OBJECTS)