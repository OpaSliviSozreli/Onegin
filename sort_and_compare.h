#ifndef _SORT_AND_COMPARE_H
#define _SORT_AND_COMPARE_H

#include "const.h"
#include "structs.h"

enum BEGINNING_OF_STR
{
    BEGINNING_OF_STR1 = 1,
    BEGINNING_OF_STR2 = 2
};

int  reversed_compare_strings( LineStat* line_stat1, LineStat* line_stat2 );
void sort( LinesOfEugeneOnegin *lines_parameters, size_t size_of_cell, int size_of_array,   int curr_compare( LineStat* line_stat1, LineStat* line_stat2 ) );
int  forward_compare_strings( LineStat* line_stat1, LineStat* line_stat2 );

#endif