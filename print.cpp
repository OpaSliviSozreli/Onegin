#include <stdio.h> 

#include "print.h"

void print_onegin_text( char **ptrs_to_beginning_of_strings, int number_of_lines )
{
    for ( int i = 0; i < number_of_lines; i++ )
        printf( "%s\n", **ptrs_to_beginning_of_strings );
}
