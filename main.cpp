#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_and_output.h"
#include "sort_and_compare.h"
#include "const.h"
#include "structs.h"
#include "array_of_pointers.h"


int main( const int argc, const char *argv[] )
{   
    LinesOfEugeneOnegin lines_parameters = {};
    TextOfEugeneOnegin original_text = {};
//----------------------------------------------------------------------------------------------
    //fprintf( stderr, "here in main before anything" );
//----------------------------------------------------------------------------------------------
    input_onegin( &original_text );
//----------------------------------------------------------------------------------------------
    //fprintf( stderr, "here in main after copying the file in bufffer" );
//----------------------------------------------------------------------------------------------
   split_text_into_lines( &lines_parameters, &original_text );
//----------------------------------------------------------------------------------------------
    //fprintf( stderr, "here in main, whwere is my favourite place for debug" );
    // printf("----------------------------------------------------\n");
    // for ( size_t i = 0; i < original_text.number_of_successfully_read_elements; i++ )
    // {
    //     fprintf( stderr, "<%c><%d>\n", original_text.text[i], original_text.text[i] );
    // }
    // printf("----------------------------------------------------\n");
//----------------------------------------------------------------------------------------------
    int ( *curr_compare )( LineStat* line_stat1, LineStat* line_stat2 ) = NULL;

    if ( argc == 2 )
    {
        if ( strcmp( argv[1], "backward" ) == 0 ) 
            curr_compare = reversed_compare_strings; 

        if ( strcmp( argv[1], "forward" ) == 0 ) 
            curr_compare = forward_compare_strings; 
    }
    
    sort( &lines_parameters, sizeof( char* ), lines_parameters.number_of_lines,  curr_compare );

    print_sorted_text( &lines_parameters );

    return 0;   
}




