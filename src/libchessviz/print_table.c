#include <libchessviz/print_table.h>

void print_table(
        int hod,
        char text[],
        int znak,
        int znak1,
        int tab[Weight][Height],
        FILE* ofile)
{
    int p = 1;
    printf("\n");
    fprintf(ofile, "\n");
    if (hod != 0) {
        printf(" %d. ", hod);
        fprintf(ofile, " %d. ", hod);
    }
    if (znak != 0 && znak1 != 0)
        for (int i = znak; i <= znak1; i++) {
            printf("%c", text[0 + i]);
            fprintf(ofile, "%c", text[0 + i]);
        }
    printf(" \n");
    fprintf(ofile, " \n");
    for (int i = 0; i < Weight; i++) {
        printf("%d", p);
        fprintf(ofile, "%d", p);
        for (int j = 0; j < Height; j++) {
            if (tab[i][j] == 0) {
                printf("  ");
                fprintf(ofile, "  ");
            }
            if (tab[i][j] == 1) {
                printf(" p");
                fprintf(ofile, " p");
            } else if (tab[i][j] == 10) {
                printf(" P");
                fprintf(ofile, " P");
            }
            if (tab[i][j] == 2) {
                printf(" r");
                fprintf(ofile, " r");
            } else if (tab[i][j] == 20) {
                printf(" R");
                fprintf(ofile, " R");
            }
            if (tab[i][j] == 3) {
                printf(" n");
                fprintf(ofile, " n");
            } else if (tab[i][j] == 30) {
                printf(" N");
                fprintf(ofile, " N");
            }
            if (tab[i][j] == 4) {
                printf(" b");
                fprintf(ofile, " b");
            } else if (tab[i][j] == 40) {
                printf(" B");
                fprintf(ofile, " B");
            }
            if (tab[i][j] == 5) {
                printf(" q");
                fprintf(ofile, " q");
            } else if (tab[i][j] == 50) {
                printf(" Q");
                fprintf(ofile, " Q");
            }
            if (tab[i][j] == 6) {
                printf(" k");
                fprintf(ofile, " k");
            } else if (tab[i][j] == 60) {
                printf(" K");
                fprintf(ofile, " K");
            }
        }
        p++;
        printf("\n");
        fprintf(ofile, "\n");
    }
    printf("  a b c d e f g h\n");
    fprintf(ofile, "  a b c d e f g h\n");
}
