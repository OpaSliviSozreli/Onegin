#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "bubble_sort.h"

void sort( int number_of_lines, char *ptrs_to_beginning_of_strings[] )
{   
    assert( ptrs_to_beginning_of_strings != NULL );

    for ( int max_str = number_of_lines - 1; max_str > 0; max_str-- )
    {
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
}