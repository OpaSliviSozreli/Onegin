#include <stdio.h>
#include <assert.h>

#include "array_of_pointers.h"

int count_number_of_lines( char* text, size_t number_of_successfully_read_elements )
{   
    assert( text != NULL );

    int number_of_lines = 0;
    
    for ( size_t i = 0; i < number_of_successfully_read_elements; i++ )
    {
        if ( text[i] == '\n' ) // TODO: last string
            number_of_lines++;
    }

    return number_of_lines;
}

void fill_array_of_pointers( char *ptrs_to_beginning_of_strings[], char *text, size_t number_of_successfully_read_elements )
{   
    //assert( text != NULL );

    ptrs_to_beginning_of_strings[0] = text;
    int cur_str = 1;

    for ( size_t i = 1; i < number_of_successfully_read_elements; i++ ) 
    {   
        if ( text[i] == '\r')
           text[i] = '\0';
         
        if ( text[i] == '\n' ) 
        {
            text[i] = '\0';
            ptrs_to_beginning_of_strings[cur_str++] = &text[i + 1];
        }
    }
}