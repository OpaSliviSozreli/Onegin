#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "array_of_pointers.h"

void count_number_of_lines( LinesOfEugeneOnegin *lines_parameters, TextOfEugeneOnegin *original_text )
{   
    assert( original_text->text != NULL );

    for ( size_t i = 0; i < original_text->number_of_successfully_read_elements; i++ )
    {
        if ( original_text->text[i] == '\n' ) 
            lines_parameters->number_of_lines++;
    }

    original_text->text[original_text->number_of_successfully_read_elements - 1] = '\n';
}

void fill_array_of_pointers( LinesOfEugeneOnegin *lines_parameters, TextOfEugeneOnegin *original_text )
{   
    assert( original_text->text != NULL );

    lines_parameters->ptrs_to_strings = ( char ** ) calloc( lines_parameters->number_of_lines + 1, sizeof( char * ) );
    lines_parameters->end_of_str = ( char ** ) calloc( lines_parameters->number_of_lines + 1, sizeof( char * ) );
// TODO: поправить на структуры
    lines_parameters->ptrs_to_strings[0] = &original_text->text[0];

    int cur_str = 1;
    int eldack = 0;
//----------------------------------------------------------------------------------------------
    //fprintf(stderr, "size = %d\n", original_text->number_of_successfully_read_elements);
//------------------------------------------------------------------------------------------------
    for ( size_t i = 0; i < original_text->number_of_successfully_read_elements; i++ ) 
    {   
//---------------------------------------------------------------------------------------------------------
        //fprintf( stderr, "%p\n", &original_text->text[i] );
//---------------------------------------------------------------------------------------------------------
        if ( original_text->text[i] == '\r' ) 
        {
//---------------------------------------------------------------------------------------------------------
            //fprintf(stderr, "before change: <%c><%d>\n", original_text->text[i], original_text->text[i]);
//----------------------------------------------------------------------------------------------------------
            original_text->text[i] = '\0';
//------------------------------------------------------------------------------------------------
            //fprintf(stderr, "after change:  <%c><%d>\n", original_text->text[i], original_text->text[i]);
            //fprintf( stderr, " <%d>, %p\n", i, &original_text->text[i] );
//-----------------------------------------------------------------------------------------------------------------
            lines_parameters->end_of_str[eldack++] = &original_text->text[i];
//------------------------------------------------------------------------------------------------
            //fprintf( stderr, "%d, <%p><%s>\n", eldack - 1, lines_parameters->end_of_str[eldack - 1], lines_parameters->end_of_str[eldack - 1] );
//------------------------------------------------------------------------------------------------
        }
         
        if ( original_text->text[i] == '\n' ) 
        {
            original_text->text[i] = '\0';
//------------------------------------------------------------------------------------------------
            //fprintf( stderr, "<%c><%d>\n", original_text->text[i], original_text->text[i] );
//------------------------------------------------------------------------------------------------
            lines_parameters->ptrs_to_strings[cur_str++] = &original_text->text[i + 1];
//------------------------------------------------------------------------------------------------
            //fprintf( stderr, "%d, <%p><%s>\n", cur_str - 1, lines_parameters->ptrs_to_strings[cur_str -1], lines_parameters->ptrs_to_strings[cur_str - 1] );
//------------------------------------------------------------------------------------------------       
        }
    }

//------------------------------------------------------------------------------------------------
    //lines_parameters->end_of_str[lines_parameters->number_of_lines] = &original_text->text[original_text->number_of_successfully_read_elements];
//------------------------------------------------------------------------------------------------
}

void split_text_into_lines( LinesOfEugeneOnegin *lines_parameters, TextOfEugeneOnegin *original_text )
{
    count_number_of_lines(  lines_parameters, original_text ); 
    fill_array_of_pointers( lines_parameters, original_text ); 
}