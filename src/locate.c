#include <windows.h>
#include <stdio.h>
#include "bofdefs.h"

void locate( char * path, char * type, char * match, int level, int max ) {
    WIN32_FIND_DATA currentToken;
    HANDLE          hToken;
    TCHAR           searchPath[MAX_PATH];

    /* do i need to worry of a buffer overflow here? */
    strcpy( searchPath, path );
    strcat( searchPath, "\\*" );
    /* yeah probably, TODO: fix this */

    hToken = FindFirstFileA( searchPath, & currentToken );
    if ( hToken == INVALID_HANDLE_VALUE ) {
        return;
    }

    do {
        if ( strcmp( currentToken.cFileName, "." ) == 0 || strcmp( currentToken.cFileName, ".." ) == 0 ) {
            continue;
        }

        if ( currentToken.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) {
            /*
             * We've entered a directory, recurse to win.
             */

            TCHAR subDir[MAX_PATH];

            strcpy( subDir, path );
            strcat( subDir, "\\" );
            strcat( subDir, currentToken.cFileName );

            if ( level <= max ) {
                locate( subDir, type, match, level + 1, max );
            }

        } else {
            /*
                * We've found a file, check if it matches the type and match.
             */
            if ( strcmp( type, "/f" ) == 0 ) {
                if ( strstr( currentToken.cFileName, match ) != NULL ) {
                    Print( "%s\\%s\n", path, currentToken.cFileName );
                }
            }
        }
    } while ( FindNextFileA( hToken, & currentToken ) != 0 );
    FindClose( hToken );
}
