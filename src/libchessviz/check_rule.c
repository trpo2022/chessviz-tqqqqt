#include <libchessviz/check_rule.h>

void check_rule(
        int step,
        int x,
        int y,
        int x1,
        int y1,
        int flag,
        int figures,
        int** error)
{
    switch (figures) {
    case 1:
    case 10: // peshka
        if ((abs(y1 - y) > 2 || abs(x1 - x) > 0) && flag == 1)
            **error = 1;
        if ((abs(x1 - x) > 1 || abs(y1 - y) > 1) && flag == 2)
            **error = 1;
        if (abs(x1 - x) > 1 && (y != 7 || y != 1))
            **error = 1;
        if (abs(x1 - x) > Height || abs(y1 - y) > Weight)
            **error = 5;
        break;
    case 2:
    case 20: // ladya
        if (abs(x1 - x) > 0 && abs(y1 - y) > 0)
            **error = 1;
        if (abs(x1 - x) > Height || abs(y1 - y) > Weight)
            **error = 5;
        break;
    case 3:
    case 30: // koni
        if (abs(x1 - x) > Height || abs(y1 - y) > Weight)
            **error = 5;
        if ((abs(y1 - y) == 2 && abs(x1 - x) == 1)
            || (abs(y1 - y) == 1 && abs(x1 - x) == 2)) {
        } else
            **error = 1;
        break;
    case 4:
    case 40: // slon
        if (abs(x1 - x) > Height || abs(y1 - y) > Weight)
            **error = 5;
        if ((abs(x1 - x) > 0 && abs(y1 - y) == 0)
            || ((y1 - y) > 0 && (x1 - x) == 0))
            **error = 1;
        break;
    case 5:
    case 50: // ferz
        if (abs(x1 - x) > Height || abs(y1 - y) > Weight)
            **error = 5;
        if ((abs(x1 - x) == 2 && abs(y1 - y) == 1)
            || (abs(x1 - x) == 1 && abs(y1 - y) == 2))
            **error = 1;
        break;
    case 6:
    case 60: // korol
        if (abs(x1 - x) > Height || abs(y1 - y) > Weight)
            **error = 5;
        if (abs(x1 - x) > 1 && abs(y1 - y) > 1)
            **error = 1;
        break;
    }
}
