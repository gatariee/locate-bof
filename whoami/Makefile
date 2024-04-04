BOFNAME := whoami
BIN_PATH := bin
LIBINCLUDE := -l secur32

CC_x64 = x86_64-w64-mingw32-gcc.exe

all:
	$(CC_x64) -c entry.c -o $(BIN_PATH)/$(BOFNAME).x64.o    -DBOF

test:
	$(CC_x64)    entry.c -o $(BIN_PATH)/$(BOFNAME).x64.exe $(LIBINCLUDE)
