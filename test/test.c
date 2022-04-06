#include <ctest.h>
#include <stdio.h>

CTEST(read_tt, simple_read)
{
    FILE *file = fopen("test.txt","r");
    char result[20];
    fgets(result,20,file);
    fclose(file);

    const char expected[20] = {'a',
                               'c',
                               'c',
                               'd',
                               'e',
                               'r',
                               'f',
                               'g',
                               't',
                               'o',
                               'r',
                               'u',
                               'e',
                               'h',
                               'd',
                               'n',
                               'b',
                               'c',
                               'd'};

        ASSERT_STR(result, expected);
}
