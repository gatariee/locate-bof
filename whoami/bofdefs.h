#include <stdio.h>

#ifdef BOF
WINBASEAPI HANDLE  WINAPI KERNEL32$GetProcessHeap();
WINBASEAPI void *  WINAPI KERNEL32$HeapAlloc( HANDLE, DWORD, SIZE_T );
WINBASEAPI BOOL    WINAPI KERNEL32$HeapFree( HANDLE, DWORD, PVOID );
WINBASEAPI BOOLEAN WINAPI SECUR32$GetUserNameExA( int, LPSTR, PULONG );

#define GetProcessHeap     KERNEL32$GetProcessHeap
#define HeapAlloc          KERNEL32$HeapAlloc
#define HeapFree           KERNEL32$HeapFree
#define GetUserNameExA     SECUR32$GetUserNameExA

#endif
//#define intAlloc( size ) HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, size );
//#define intFree( size )  HeapFree ( GetProcessHeap(), 0, size );

#ifdef BOF
#define Print( ... ) { \
    BeaconPrintf(CALLBACK_OUTPUT, __VA_ARGS__); \
}

#else
#define Print( ... ) { \
     fprintf(stdout, __VA_ARGS__); \
     fprintf(stdout, "\n"); \
}

#endif