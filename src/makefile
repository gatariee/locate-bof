BOFNAME := locate
BIN_PATH := bin
LIBINCLUDE :=

CC_x64 = x86_64-w64-mingw32-gcc.exe

all:
	$(CC_x64) -c entry.c -o $(BIN_PATH)/$(BOFNAME).x64.o    -DBOF

build:
	$(CC_x64) -c entry.c -o $(BIN_PATH)/$(BOFNAME).x64.o    -DBOF
	$(CC_x64)    entry.c -o $(BIN_PATH)/$(BOFNAME).x64.exe $(LIBINCLUDE)

test:
	$(CC_x64)    entry.c -o $(BIN_PATH)/$(BOFNAME).x64.exe $(LIBINCLUDE)