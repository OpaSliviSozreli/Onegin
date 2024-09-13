#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubble_sort.h"
#include "print.h"
#include "sort_backwards.h"
#include "const.h"

int count_number_of_lines( char *text , int count_of_lines );

int number_of_lines = 0;

int main( const char *argv[] )
{
    const char *filename = "Onegin.txt";

    FILE *fp = fopen( filename, "rb" );

    if ( !fp )
        return SYS_ERROR;

    fseek( fp , 9 , SEEK_END );
    long file_size = ftell( fp );                         
    rewind ( fp );

    char *text = ( char * ) calloc( file_size, sizeof( char ) );
    size_t number_of_successfully_read_elements = fread( text, sizeof( char ), file_size, fp );

    fclose(fp);

    number_of_lines = count_number_of_lines( text, number_of_successfully_read_elements );
    char **ptrs_to_beginning_of_strings = ( char ** ) calloc( number_of_lines + 1, sizeof( char * ));

    if ( number_of_successfully_read_elements != file_size )
        return ERROR_OF_READING;

    int cur_str = 0;

    for ( int i = 0; i < number_of_successfully_read_elements; i++ )
    {
        if ( text[i] == '\n' )
            *ptrs_to_beginning_of_strings[cur_str++] = text[i + 1];
    }

    if ( strcmp( argv[2], "-b" ) == 0 )
        sort_backwards( ptrs_to_beginning_of_strings, number_of_lines ); 
    else
        sort( ptrs_to_beginning_of_strings, number_of_lines );

    print_onegin_text( ptrs_to_beginning_of_strings, number_of_lines );

    return 0;   
}

int count_number_of_lines( char *text, size_t number_of_successfully_read_elements )
{
    for ( int i = 0; i < number_of_successfully_read_elements; i++ )
    {
        if ( text[i] == '\n' )
            number_of_lines++;
    }

    return number_of_lines;
}



