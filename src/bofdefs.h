#include <windows.h>
#include <stdio.h>
#include <ctype.h>

/**
 * Original Authors:
    https://github.com/outflanknl/C2-Tool-Collection/blob/main/BOF/Kerberoast/Kerberoast.cna
    https://github.com/trustedsec/CS-Situational-Awareness-BOF
    ^^ thanks a lot <3
 */

#ifdef BOF
#define Print( ... ) { \
    BeaconPrintf(CALLBACK_OUTPUT, __VA_ARGS__); \
}

DECLSPEC_IMPORT char * __cdecl MSVCRT$strcpy(char * __restrict__ __dst, const char * __restrict__ __src);
DECLSPEC_IMPORT int __cdecl MSVCRT$strcmp(const char *_Str1,const char *_Str2);
DECLSPEC_IMPORT char * __cdecl MSVCRT$strcat(char * __restrict__ _Dest,const char * __restrict__ _Source);
DECLSPEC_IMPORT char* __cdecl MSVCRT$strstr(const char* _Str, const char* _SubStr);

WINBASEAPI HANDLE WINAPI KERNEL32$FindFirstFileA (char * lpFileName, LPWIN32_FIND_DATA lpFindFileData);
WINBASEAPI WINBOOL WINAPI KERNEL32$FindNextFileA (HANDLE hFindFile, LPWIN32_FIND_DATA lpFindFileData);
WINBASEAPI WINBOOL WINAPI KERNEL32$FindClose (HANDLE hFindFile);

#define strcpy         MSVCRT$strcpy
#define strcmp         MSVCRT$strcmp
#define strcat         MSVCRT$strcat
#define strstr         MSVCRT$strstr

#define FindFirstFileA KERNEL32$FindFirstFileA
#define FindNextFileA  KERNEL32$FindNextFileA
#define FindClose      KERNEL32$FindClose

#else
#define Print( ... ) { \
     fprintf(stdout, __VA_ARGS__); \
     fprintf(stdout, "\n"); \
}

#endif

