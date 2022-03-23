#include <chessviz/start_table.h>

void starttable(int tab[Weight][Height])
{
    for (int y = 0; y < Weight; y++) {
        switch (y) {
        case 0:
            tab[y][0] = 2;
            tab[y][1] = 3;
            tab[y][2] = 4;
            tab[y][3] = 5;
            tab[y][4] = 6;
            tab[y][5] = 4;
            tab[y][6] = 3;
            tab[y][7] = 2;
            break;
        case 7:
            tab[y][0] = 20;
            tab[y][1] = 30;
            tab[y][2] = 40;
            tab[y][3] = 50;
            tab[y][4] = 60;
            tab[y][5] = 40;
            tab[y][6] = 30;
            tab[y][7] = 20;
            break;
        case 1:
            for (int x = 0; x < Height; x++) {
                tab[y][x] = 1;
            }
            break;
        case 6:
            for (int x = 0; x < Height; x++) {
                tab[y][x] = 10;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        default:
            for (int x = 0; x < Height; x++) {
                tab[y][x] = 0;
            }
            break;
        }
    }
}
