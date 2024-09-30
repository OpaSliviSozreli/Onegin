#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "sort_and_compare.h"

int reversed_compare_strings( LineStat* line_stat1, LineStat* line_stat2 )
{  
//--------------------------------------------    
    // for ( size_t i = 0; i < 14; i++ )
    // {  
    //     fprintf( stderr, "%p\n", str1 );
    //     fprintf( stderr, "%p\n", str2 );
    // }
    //printf("----------------------------------------------------\n");
//--------------------------------------------       
    assert( line_stat1 ); 
    assert( line_stat2 );
//--------------------------------------------    
    // for ( size_t i = 0; i < 14; i++ )
    // {  
    //     fprintf( stderr, "%c\n", *end_of_str1 );
    //     fprintf( stderr, "%c\n", *end_of_str2 );
    // }
//--------------------------------------------    

    size_t len_str1 = line_stat1->string_end - line_stat1->string_start;
    size_t len_str2 = line_stat2->string_end - line_stat2->string_start;
//--------------------------------------------    
    //fprintf( stderr, "%d %d\n", len_str1, len_str2 );
//--------------------------------------------    
    char* ptr_to_cur_symbol_1 = line_stat1->string_end;
    char* ptr_to_cur_symbol_2 = line_stat2->string_end;
//--------------------------------------------------------
    // fprintf( stderr, "str1 = <%s><%p> end_of_str1 = <%p>\n, str2 = <%s><%p>, end_of_str2 = <%p>\n",
    //          str1, end_of_str1, str2, end_of_str2 );
//--------------------------------------------------------
//--------------------------------------------    
    //printf("ELDAK");
//--------------------------------------------   
    for ( size_t i = 0; i < len_str1; i++ )
    {
        if ( isalpha( *ptr_to_cur_symbol_1 ) == 0 )                                                 
            ptr_to_cur_symbol_1--;
    }

    for ( size_t i = 0; i < len_str2; i++ )
    {
        if ( isalpha( *ptr_to_cur_symbol_2 ) == 0 )
            ptr_to_cur_symbol_2--;
    }

    while ( tolower( *ptr_to_cur_symbol_1 ) == tolower( *ptr_to_cur_symbol_2 ) ) 
    {  
        ptr_to_cur_symbol_1--;
        ptr_to_cur_symbol_2--; 

        if ( ptr_to_cur_symbol_1 == line_stat1->string_start )  
            return BEGINNING_OF_STR1;

        if ( ptr_to_cur_symbol_2 == line_stat2->string_start )
            return BEGINNING_OF_STR2;
    }

    return tolower( *ptr_to_cur_symbol_1 ) - tolower( *ptr_to_cur_symbol_2 );
}

int forward_compare_strings( LineStat* line_stat1, LineStat* line_stat2 )
 {
    assert( line_stat1 ); 
    assert( line_stat2 );

    size_t len_str1 = line_stat1->string_end - line_stat1->string_start;
    size_t len_str2 = line_stat2->string_end - line_stat2->string_start;
//--------------------------------------------------------
    for ( size_t i = 0; i < len_str1; i++ )
        fprintf( stderr, "%s\n", line_stat1->string_start );
//--------------------------------------------------------
    char* ptr_to_cur_symbol_1 = line_stat1->string_start;
    char* ptr_to_cur_symbol_2 = line_stat2->string_start;

    for ( size_t i = 0; i < len_str1; i++ )
    {
        if ( isalpha( *ptr_to_cur_symbol_1 ) == 0 )                                                 
            ptr_to_cur_symbol_1++;
    }

    for ( size_t i = 0; i < len_str2; i++ )
    {
        if ( isalpha( *ptr_to_cur_symbol_2 ) == 0 )
            ptr_to_cur_symbol_2++;
    }

    while( tolower( *ptr_to_cur_symbol_1 ) == tolower( *ptr_to_cur_symbol_2 ) ) 
    {
        ptr_to_cur_symbol_1++;
        ptr_to_cur_symbol_2++;
        
        if ( ( *ptr_to_cur_symbol_1 + *ptr_to_cur_symbol_2 ) == '\0') 
            return END_OF_STRING;
    }

    return tolower( *ptr_to_cur_symbol_1 ) - tolower( *ptr_to_cur_symbol_2 );
}


void sort( LinesOfEugeneOnegin *lines_parameters, size_t size_of_cell, int size_of_array,   int curr_compare( LineStat* line_stat1, LineStat* line_stat2 ) ) 
{
    assert( lines_parameters->ptrs_to_strings != NULL );

    for ( int max_str = lines_parameters->number_of_lines - 1; max_str > 0; max_str-- )
    {
        for ( size_t i = 0; i < (size_t) ( lines_parameters->number_of_lines - 1 ); i++ )
        {  
//----------------------------------------------------------------------------------------------
            //fprintf( stderr, "here in sort_backwards checkin if everuthing ok before comparing" );
            //fprintf( stderr, "%d\n", lines_parameters->number_of_lines );
//----------------------------------------------------------------------------------------------
            if ( curr_compare( lines_parameters->array_of_lines_stat[i],
                               lines_parameters->array_of_lines_stat[i + 1] ) > 0 )
            {
                char* temp = lines_parameters->ptrs_to_strings[i];

                lines_parameters->ptrs_to_strings[i]     = lines_parameters->ptrs_to_strings[i + 1];
                lines_parameters->ptrs_to_strings[i + 1] = temp;
            }
        }
    }
}

