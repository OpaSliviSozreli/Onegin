#include <stdio.h>
#include <string.h>

#include "bubble_sort.h"
#include "print.h"

int main()
{
    const char * filename = "Onegin.txt";

    FILE *fp = fopen( filename, "r" );

    if ( !fp )
    {
        printf ( "Something went wrong" );
        return SYS_ERROR;
    }

    else
    {
        char text[DEFAULT_NUMBER_OF_LINES][DEFAULT_NUMBER_OF_RAWS] = {};

        fgets( ( char* )text, DEFAULT_NUMBER_OF_RAWS, fp );
        sort( text );
        print( text );

        fclose(fp);
    }

    return 0;
}


