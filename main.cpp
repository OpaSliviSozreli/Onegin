#include <stdio.h>
#include <string.h>

#include "bubble_sort.h"
#include "print.h"

int main()
{
    const char *filename = "Onegin.txt";

    FILE *fp = fopen( filename, "r" );

    if ( !fp )
    {
        printf ( "Something went wrong" );
        return SYS_ERROR;
    }

    else
    {
        char text[DEFAULT_NUMBER_OF_RAWS][DEFAULT_NUMBER_OF_COLUMNS] = {};
        char str[DEFAULT_NUMBER_OF_COLUMNS + 1] ={};

        int count_of_raws = 0;

        for( int i = 0; i < DEFAULT_NUMBER_OF_RAWS; i++ )
        {
            char ch = 0;

            for( int j = 0; ( ch = getc( fp ) ) != '\n' && ( ch != WINDOWS_EOF ); j++ )
                text[i][j] = ch;

            if( ch == WINDOWS_EOF )
            {
              printf( "#Program reach the end of file" );
              break;
            }

            else
            {
              text[i][0] = '\0';
              ++count_of_raws;
            }

            sort( text );
            print( text, count_of_raws );
        }

        fclose(fp);
    }

    return 0;
}



