#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <stdio.h>

struct LineStat 
{
    char* string_start;
    char* string_end;
};

struct LinesOfEugeneOnegin
{
    int        number_of_lines;
    LineStat   lines_stat;
    LineStat** array_of_lines_stat;
    char**     ptrs_to_strings;       
};

struct TextOfEugeneOnegin
{
    char*  text;
    size_t number_of_successfully_read_elements;
};

#endif