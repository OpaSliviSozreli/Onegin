#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

const int DEFAULT_NUMBER_OF_RAWS = 50;
const int DEFAULT_NUMBER_OF_COLUMNS = 10;

const int SYS_ERROR = 0;
const int END_OF_STRING = 0;

const int WINDOWS_EOF = 26;

void sort( char text[DEFAULT_NUMBER_OF_RAWS][DEFAULT_NUMBER_OF_COLUMNS] );
int  compare_strings( char *str1, char *str2 );

#endif
