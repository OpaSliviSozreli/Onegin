#ifndef _SORT_BACKWARDS_H
#define _SORT_BACKWARDS_H

#include "bubble_sort.h"
#include "const.h"

enum BEGINNING_OF_STR
{
    BEGINNING_OF_STR1 = 1,
    BEGINNING_OF_STR2 = 2
};

int  reversed_compare_strings( char *str1, char *str2 );
void sort_backwards( int number_of_lines, char *ptrs_to_beginning_of_strings[] );

#endif