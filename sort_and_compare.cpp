#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "sort_and_compare.h"

int reversed_compare_strings( char* str1, char* str2, char* end_of_str1, char* end_of_str2 )
{  
//--------------------------------------------    
    // for ( size_t i = 0; i < 14; i++ )
    // {  
    //     fprintf( stderr, "%p\n", str1 );
    //     fprintf( stderr, "%p\n", str2 );
    // }
    //printf("----------------------------------------------------\n");
//--------------------------------------------       
    assert( str1        != NULL ); 
    assert( str2        != NULL );
//--------------------------------------------    
    // for ( size_t i = 0; i < 14; i++ )
    // {  
    //     fprintf( stderr, "%c\n", *end_of_str1 );
    //     fprintf( stderr, "%c\n", *end_of_str2 );
    // }
//--------------------------------------------    
    assert( end_of_str1 != NULL );
    assert( end_of_str2 != NULL );
    
    size_t len_str1 = end_of_str1 - str1;
    size_t len_str2 = end_of_str2 - str2;
//--------------------------------------------    
    //fprintf( stderr, "%d %d\n", len_str1, len_str2 );
//--------------------------------------------    
    char* ptr_to_cur_symbol_1 = end_of_str1;
    char* ptr_to_cur_symbol_2 = end_of_str2;
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

        if ( ptr_to_cur_symbol_1 == str1 )  
            return BEGINNING_OF_STR1;

        if ( ptr_to_cur_symbol_2 == str2 )
            return BEGINNING_OF_STR2;
    }

    return tolower( *ptr_to_cur_symbol_1 ) - tolower( *ptr_to_cur_symbol_2 );
}

int forward_compare_strings( char* str1, char* str2, char* end_of_str1, char* end_of_str2 )
 {
    assert( str1        != NULL ); 
    assert( str2        != NULL );
    assert( end_of_str1 != NULL );
    assert( end_of_str2 != NULL );
    
    size_t len_str1 = end_of_str1 - str1;
    size_t len_str2 = end_of_str2 - str2;

    char* ptr_to_cur_symbol_1 = str1;
    char* ptr_to_cur_symbol_2 = str2;

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

//qsort (array, sizeof(cell), size_of_array, comparator);

//sort (Lines_parametres, comparator) // TODO: make args like in qsort
// TODO: make comparators like standard

void sort( LinesOfEugeneOnegin *lines_parameters, int ( *curr_compare )( char* str1, char* str2, char* end_of_str1, char* end_of_str2 ) ) 
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
            if ( curr_compare( lines_parameters->ptrs_to_strings[i],
                               lines_parameters->ptrs_to_strings[i + 1],
                               lines_parameters->end_of_str[i], 
                               lines_parameters->end_of_str[i + 1] ) > 0 )
            {
                char* temp = lines_parameters->ptrs_to_strings[i];

                lines_parameters->ptrs_to_strings[i]     = lines_parameters->ptrs_to_strings[i + 1];
                lines_parameters->ptrs_to_strings[i + 1] = temp;

                temp = lines_parameters->end_of_str[i];
                lines_parameters->end_of_str[i] = lines_parameters->end_of_str[i + 1];
                lines_parameters->end_of_str[i + 1] = temp;
            }
        }
    }
}

