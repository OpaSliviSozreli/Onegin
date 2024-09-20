#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "print.h"

void print_onegin_text( int number_of_lines, char *ptrs_to_beginning_of_strings[] )
{
    FILE * fp_result = fopen ( "Result.txt" , "wb" );

    //char buffer[number_of_lines] = {};

    for ( int i = 0; i < number_of_lines; i++ )
    {
        fputs( ptrs_to_beginning_of_strings[i], fp_result );
        fputs( "\n", fp_result );
    }

    fclose ( fp_result );
}

int input_onegin( char **text )
{
    const char *filename = "Onegin.txt";

    FILE *fp = fopen( filename, "rb" );

    if ( !fp )
        return SYS_ERROR;

    fseek( fp, 0, SEEK_END ); // make as func
    size_t file_size = ftell( fp );                         
    rewind ( fp );

    *text = ( char * ) calloc( file_size + 1, sizeof( char ) );
    size_t number_of_successfully_read_elements = fread( *text, sizeof( char ), file_size, fp );

    fclose( fp );

    if ( number_of_successfully_read_elements != file_size )
        return ERROR_OF_READING;
    return number_of_successfully_read_elements;
}
