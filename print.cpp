#include "print.h"

void print( char text[][DEFAULT_NUMBER_OF_RAWS] )
{
    for ( int i = 0; i < DEFAULT_NUMBER_OF_LINES; i++ )
    {
            for ( int j = 0; j < DEFAULT_NUMBER_OF_RAWS; j++ )
            {
                printf( "%c", text[i][j] );
            }
    }
}
