#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubble_sort.h"
#include "print.h"
#include "sort_backwards.h"
#include "const.h"
#include "array_of_pointers.h"

int main( const int argc, const char *argv[] )
{
    char *text = NULL;

    size_t number_of_successfully_read_elements = input_onegin( &text ); 
    
    int number_of_lines = count_number_of_lines( text, number_of_successfully_read_elements );
    char **ptrs_to_beginning_of_strings = ( char ** ) calloc( number_of_lines + 1, sizeof( char * ));

    fill_array_of_pointers( ptrs_to_beginning_of_strings, text, number_of_successfully_read_elements ); 
    
    // if ( argc == 2)
    // {
    //     if ( strcmp( argv[1], "-b" ) == 0 )
    //         sort_backwards( number_of_lines, ptrs_to_beginning_of_strings ); 
    // }
    // else
    //     sort( number_of_lines, ptrs_to_beginning_of_strings );

    sort_backwards( number_of_lines, ptrs_to_beginning_of_strings ); 
    print_onegin_text( number_of_lines, ptrs_to_beginning_of_strings );

    return 0;   
}




