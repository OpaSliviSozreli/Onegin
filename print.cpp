#include "print.h"

void print( char text[DEFAULT_NUMBER_OF_RAWS][DEFAULT_NUMBER_OF_COLUMNS], int count_of_raws )
{
    for ( int i = 0; i < count_of_raws; i++ )
        printf( "%s\n", text[i] );
}
