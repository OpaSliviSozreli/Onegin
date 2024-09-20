int main()
{
    const char * filename = "Onegin.txt";

    char text[DEFAULT_STRING_LENGTHS][DEFAULT_NUMBER_OF_RAWS] = {};

    FILE *fp = fopen( filename, "r" );

    if ( !fp )
    {
        fprintf ( "Something went wrong" );
        return SYS_ERROR;
    }

    else
    {
        fgets( text, DEFAULT_NUMBER_OF_RAWS, fp );
        sort( text );
        print( text);

        fclose(fp);
    }
}

//onegin.txt --> program
//
//onegin_sorted_1.txt -> � ������ ������
//onegin_sorted_2.txt -> � ����� ������
//
//MyQsort �� ��������
//�� ������� ����������� qsort � ���� bubble sort


