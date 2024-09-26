#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <stdio.h>

struct LinesOfEugeneOnegin
{
    int number_of_lines;
//    LineStat* line_stat;
//    LineStat** lines_stat;
    char** ptrs_to_strings;   
    char** end_of_str;        
};

// LineStat {
//     char* string;
//     size_t string_len;
// };

// //или

// struct LineStat 
// {
//     char* string_start;
//     char* string_end;
// };

struct TextOfEugeneOnegin
{
    char* text;
    size_t number_of_successfully_read_elements;
};

#endif