#ifndef _SORT_AND_COMPARE_H
#define _SORT_AND_COMPARE_H

#include "const.h"
#include "structs.h"

enum BEGINNING_OF_STR
{
    BEGINNING_OF_STR1 = 1,
    BEGINNING_OF_STR2 = 2
};

int  reversed_compare_strings( char* str1, char* str2, char* end_of_str1, char* end_of_str2 );
void sort( LinesOfEugeneOnegin *lines_parameters,  int ( *curr_compare )( char* str1, char* str2, char* end_of_str1, char* end_of_str2 ) );
int  forward_compare_strings( char* str1, char* str2, char* end_of_str1, char* end_of_str2 );

#endif