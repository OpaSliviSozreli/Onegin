#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "sort_backwards.h"

int reversed_compare_strings( char *str1, char *str2, int number_of_lines )
{   
    for ( int i = 0; i < number_of_lines; i++ )
    {
        char *end_of_str1 = str1 + sizeof( *str1 );
        char *end_of_str2 = str2 + sizeof( *str2);

        while ( *end_of_str1 == *end_of_str2 ) 
        {   
            end_of_str1--;
            end_of_str2--;

            if ( end_of_str1 == str1 )  
                return BEGINNING_OF_STR1;

            if ( end_of_str2 == str2 )
                return BEGINNING_OF_STR2;
        }

        return *end_of_str1 - *end_of_str2;
    }
}

void sort_backwards( char **ptrs_to_beginning_of_strings, int number_of_lines )
{
    assert( ptrs_to_beginning_of_strings != NULL );

    for ( int i = 0; i < number_of_lines - 1; i++ )
    {
        if ( reversed_compare_strings( ptrs_to_beginning_of_strings[i], ptrs_to_beginning_of_strings[i + 1], number_of_lines ) > 0 )
        {
            char* temp = ptrs_to_beginning_of_strings[i];

            ptrs_to_beginning_of_strings[i]     = ptrs_to_beginning_of_strings[i + 1];
            ptrs_to_beginning_of_strings[i + 1] = temp;
        }
    }
}
