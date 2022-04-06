#include <ctest.h>
#include <stdio.h>

CTEST(read_tt, simple_read)
{
    FILE* file = fopen("test.txt", "r");
    char result[6];
    fgets(result, 6, file);
    fclose(file);

    const char expected[5] = {'e', '2', '-', 'e', '4'};

    ASSERT_STR(result, expected);
    int xx = 0, yy = 0, flag = 0, xx1 = 0, yy1 = 0;
    for (int symbol = 0; symbol < 5; symbol++) {
        if (result[symbol] == '-')
            flag = 1;
        if (result[symbol] == 'a' && flag == 0)
            xx = 0;
        else if (result[symbol] == 'b' && flag == 0)
            xx = 1;
        else if (result[symbol] == 'c' && flag == 0)
            xx = 2;
        else if (result[symbol] == 'd' && flag == 0)
            xx = 3;
        else if (result[symbol] == 'e' && flag == 0)
            xx = 4;
        else if (result[symbol] == 'f' && flag == 0)
            xx = 5;
        else if (result[symbol] == 'g' && flag == 0)
            xx = 6;
        else if (result[symbol] == 'h' && flag == 0)
            xx = 7;
        else if (result[symbol] == '1' && flag == 0)
            yy = 0;
        else if (result[symbol] == '2' && flag == 0)
            yy = 1;
        else if (result[symbol] == '3' && flag == 0)
            yy = 2;
        else if (result[symbol] == '4' && flag == 0)
            yy = 3;
        else if (result[symbol] == '5' && flag == 0)
            yy = 4;
        else if (result[symbol] == '6' && flag == 0)
            yy = 5;
        else if (result[symbol] == '7' && flag == 0)
            yy = 6;
        else if (result[symbol] == '8' && flag == 0)
            yy = 7;

        if (result[symbol] == 'a' && (flag == 1 || flag == 2))
            xx1 = 0;
        else if (result[symbol] == 'b' && (flag == 1 || flag == 2))
            xx1 = 1;
        else if (result[symbol] == 'c' && (flag == 1 || flag == 2))
            xx1 = 2;
        else if (result[symbol] == 'd' && (flag == 1 || flag == 2))
            xx1 = 3;
        else if (result[symbol] == 'e' && (flag == 1 || flag == 2))
            xx1 = 4;
        else if (result[symbol] == 'f' && (flag == 1 || flag == 2))
            xx1 = 5;
        else if (result[symbol] == 'g' && (flag == 1 || flag == 2))
            xx1 = 6;
        else if (result[symbol] == 'h' && (flag == 1 || flag == 2))
            xx1 = 7;
        else if (result[symbol] == '1' && (flag == 1 || flag == 2)) {
            yy1 = 0;
        } else if (result[symbol] == '2' && (flag == 1 || flag == 2)) {
            yy1 = 1;
        } else if (result[symbol] == '3' && (flag == 1 || flag == 2)) {
            yy1 = 2;
        } else if (result[symbol] == '4' && (flag == 1 || flag == 2)) {
            yy1 = 3;
        } else if (result[symbol] == '5' && (flag == 1 || flag == 2)) {
            yy1 = 4;
        } else if (result[symbol] == '6' && (flag == 1 || flag == 2)) {
            yy1 = 5;
        } else if (result[symbol] == '7' && (flag == 1 || flag == 2)) {
            yy1 = 6;
        } else if (result[symbol] == '8' && (flag == 1 || flag == 2)) {
            yy1 = 7;
        }
    }
    const int x = 4, y = 1, x1 = 4, y1 = 3;
    ASSERT_EQUAL(xx, x);
    ASSERT_EQUAL(yy, y);
    ASSERT_EQUAL(xx1, x1);
    ASSERT_EQUAL(yy1, y1);

    for (int symbol = 0; symbol < 5; symbol++) {
        switch ((int)result[symbol]) {
        case 'e':
            if (flag == 0)
                xx = 4;
            else
                xx1 = 4;
            break;
        case '2':
            if (flag == 0)
                yy = 1;
            else
                yy1 = 1;
            break;
        case '4':
            if (flag == 0)
                yy = 3;
            else
                yy1 = 3;
            break;
        }
    }
    ASSERT_EQUAL(xx, x);
    ASSERT_EQUAL(yy, y);
    ASSERT_EQUAL(xx1, x1);
    ASSERT_EQUAL(yy1, y1);
}
