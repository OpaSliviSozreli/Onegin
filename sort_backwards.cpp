#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "sort_backwards.h"

int reversed_compare_strings( char* str1, char* str2 )
{   
    char* end_of_str1 = str1 + strlen( str1 );
    char* end_of_str2 = str2 + strlen( str2 );

    char* ptr_to_cur_symbol_1 = end_of_str1;
    char* ptr_to_cur_symbol_2 = end_of_str2;

    while ( *ptr_to_cur_symbol_1 == *ptr_to_cur_symbol_2 ) 
    {  
        ptr_to_cur_symbol_1 = end_of_str1--;
        ptr_to_cur_symbol_2 = end_of_str2--; 

        if ( ptr_to_cur_symbol_1 == str1 )  
            return BEGINNING_OF_STR1;

        if ( ptr_to_cur_symbol_2 == str2 )
            return BEGINNING_OF_STR2;
    }

    return *ptr_to_cur_symbol_1 - *ptr_to_cur_symbol_2;
}

void sort_backwards( int number_of_lines, char *ptrs_to_beginning_of_strings[] )
{
    assert( ptrs_to_beginning_of_strings != NULL );

    for ( int max_str = number_of_lines - 1; max_str > 0; max_str-- )
    {
        for ( int i = 0; i < number_of_lines - 1; i++ )
        {  
            if ( reversed_compare_strings( ptrs_to_beginning_of_strings[i], ptrs_to_beginning_of_strings[i + 1] ) > 0 )
            {
                char* temp = ptrs_to_beginning_of_strings[i];

                ptrs_to_beginning_of_strings[i]     = ptrs_to_beginning_of_strings[i + 1];
                ptrs_to_beginning_of_strings[i + 1] = temp;
            }
        }
    }
}
