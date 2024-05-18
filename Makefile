# Determine the operating system
ifeq ($(OS),Windows_NT)
	OS_NAME := Windows
else
	OS_NAME := $(shell uname -s)
endif

# Compiler and flags
ifeq ($(OS_NAME),Windows)
	CC := x86_64-w64-mingw32-gcc
	CFLAGS := -g -Wno-everything -static -lm
else
	CC := gcc
	CFLAGS := -g -Wno-everything -pthread -lm
endif

# Source files and headers
SRCS := $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS := $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

# Targets
linux: main-linux

windows: main-windows.exe

main-linux: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

main-windows.exe: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

clean:
	rm -f main-linux main-windows.exe
