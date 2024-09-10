#include "print.h"

void print_onegin_text( char text[DEFAULT_NUMBER_OF_RAWS][DEFAULT_NUMBER_OF_COLUMNS] )
{
    for ( int i = 0; i < DEFAULT_NUMBER_OF_RAWS; i++ )
        printf( "%s\n", text[i] );
}
