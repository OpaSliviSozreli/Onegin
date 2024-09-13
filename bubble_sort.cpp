#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "bubble_sort.h"

void sort( char **ptrs_to_beginning_of_strings, int number_of_lines )
{   
    assert( ptrs_to_beginning_of_strings != NULL );

    for ( int i = 0; i < number_of_lines - 1; i++ )
    {
        if ( strcmp( ptrs_to_beginning_of_strings[i], ptrs_to_beginning_of_strings[i + 1] ) > 0 )
        {
            char* temp = ptrs_to_beginning_of_strings[i];

            ptrs_to_beginning_of_strings[i]     = ptrs_to_beginning_of_strings[i + 1];
            ptrs_to_beginning_of_strings[i + 1] = temp;
        }
    }
}

