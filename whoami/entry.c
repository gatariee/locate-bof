#include <windows.h>

#define SECURITY_WIN32

#include <security.h>
#include "beacon.h"
#include "bofdefs.h"

char * whoami() {
    char * UsrBuf = HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, 1024 );
    ULONG UsrSize = 1024;

    if ( UsrBuf == NULL ) {
        Print( "Failed to allocate memory" )
        return NULL;
    }

    EXTENDED_NAME_FORMAT NameFormat = NameSamCompatible;

    if ( ! GetUserNameExA( NameFormat, UsrBuf, & UsrSize ) ) {
        Print( "Failed to get username" );
        HeapFree( GetProcessHeap(), 0, UsrBuf );
        return NULL;
    }

    return UsrBuf;
}

#ifdef BOF

void go( char * args, int alen ) {
    char * UsrBuf = whoami();
    if ( UsrBuf == NULL ) {
        return;
    }
    BeaconPrintf( CALLBACK_OUTPUT, "Username: %s", UsrBuf );
    HeapFree( GetProcessHeap(), 0, UsrBuf );
}

#else

int main() {
    char * UsrBuf = whoami();
    if ( UsrBuf == NULL ) {
        return 1;

    }
    Print( "Username: %s", UsrBuf );
    HeapFree( GetProcessHeap(), 0, UsrBuf );
    return 0;
}

#endif
