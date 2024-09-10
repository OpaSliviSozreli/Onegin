#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "bubble_sort.h"

void sort( char text[DEFAULT_NUMBER_OF_RAWS][DEFAULT_NUMBER_OF_COLUMNS] )
{
    assert( text != NULL );

    for ( int i = 0; i < DEFAULT_NUMBER_OF_RAWS - 1; i++ )
    {
        for ( int j = 0; j < DEFAULT_NUMBER_OF_COLUMNS; j++ )
        {
            if ( compare_strings( text[i], text[i+1] ) > 0 )
            {
               char t[DEFAULT_NUMBER_OF_RAWS] = {};

               strcpy( t, text[i] );
               strcpy( text[i], text[i+1] );
               strcpy( text[i], t );
            }
        }
    }
}

int compare_strings( char *str1, char *str2 )
{
    while ( *str1 == *str2 )
    {
        if ( ( *str1++ + *str2++ ) == '\0' )
            return END_OF_STRING;
    }

    return *str1 - *str2;
}

