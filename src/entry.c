#include <windows.h>

#include "beacon.h"
#include "bofdefs.h"
#include "locate.c"

#ifdef BOF

VOID go(
        IN PCHAR Buffer,
        IN INT Length
       ) {
    datap parser;
    char * path  = NULL;
    char * type  = NULL;
    char * match = NULL;
    int level = 0;

    BeaconDataParse( & parser, Buffer, Length );

    path  = BeaconDataExtract( & parser, NULL );
    type  = BeaconDataExtract( & parser, NULL );
    match = BeaconDataExtract( & parser, NULL );
    level = BeaconDataInt( & parser );

    locate( path, type, match, 0, level );
}

#else

int main( int argc, char ** argv ) {
    char * path  = argv[ 1 ];
    char * type  = argv[ 2 ];
    char * match = argv[ 3 ];
    char * level = argv[ 4 ];

    if ( argc < 4 ) {
        Print( "Usage: %s <path> <type> <match> <level>", argv[ 0 ] );
        return 1;
    }

    int parsedLevel = strtol( level, NULL, 10 );
    locate( path, type, match, 0, parsedLevel );
}

#endif