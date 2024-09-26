#ifndef _PRINT_H_
#define _PRINT_H_

#include "const.h"
#include "structs.h"

void           print_sorted_text( LinesOfEugeneOnegin *lines_parameters  );
ReadingErrors  input_onegin( TextOfEugeneOnegin *original_text );
int            count_file_size( FILE *fp );

#endif
