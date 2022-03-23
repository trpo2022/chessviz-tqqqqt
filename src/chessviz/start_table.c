#include <chessviz/start_table.h>

void starttable(int tab[Weight][Height])
{
    for (int i = 0; i < Weight; i++) {
        switch (i) {
        case 0:
            tab[i][0] = 2;
            tab[i][1] = 3;
            tab[i][2] = 4;
            tab[i][3] = 5;
            tab[i][4] = 6;
            tab[i][5] = 4;
            tab[i][6] = 3;
            tab[i][7] = 2;
            break;
        case 7:
            tab[i][0] = 20;
            tab[i][1] = 30;
            tab[i][2] = 40;
            tab[i][3] = 50;
            tab[i][4] = 60;
            tab[i][5] = 40;
            tab[i][6] = 30;
            tab[i][7] = 20;
            break;
        case 1:
            for (int j = 0; j < Height; j++) {
                tab[i][j] = 1;
            }
            break;
        case 6:
            for (int j = 0; j < Height; j++) {
                tab[i][j] = 10;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        default:
            for (int j = 0; j < Height; j++) {
                tab[i][j] = 0;
            }
            break;
        }
    }
}
