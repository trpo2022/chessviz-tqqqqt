#include <stdio.h>
#include <stdlib.h>

#define Weight 8
#define Height 8

void starttable(int tab[Weight][Height])
{
    for (int i = 0; i < 8; i++) {
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
            for (int j = 0; j < 8; j++) {
                tab[i][j] = 1;
            }
            break;
        case 6:
            for (int j = 0; j < 8; j++) {
                tab[i][j] = 10;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        default:
            for (int j = 0; j < 8; j++) {
                tab[i][j] = 0;
            }
            break;
        }
    }
}

void printtable(
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
    for (int i = 0; i < 8; i++) {
        printf("%d", p);
        fprintf(ofile, "%d", p);
        for (int j = 0; j < 8; j++) {
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

void checkrule(
        int hod, int x, int y, int x1, int y1, int flag, int fig, int** er)
{
    switch (fig) {
    case 1:
    case 10: // peshka
        if ((abs(y1 - y) > 2 || abs(x1 - x) > 0) && flag == 1)
            **er = 1;
        if ((abs(x1 - x) > 1 || abs(y1 - y) > 1) && flag == 2)
            **er = 1;
        if (abs(x1 - x) > 1 && (y != 7 || y != 1))
            **er = 1;
        if (abs(x1 - x) > 8 || abs(y1 - y) > 8)
            **er = 5;
        break;
    case 2:
    case 20: // ladya
        if (abs(x1 - x) > 0 && abs(y1 - y) > 0)
            **er = 1;
        if (abs(x1 - x) > 8 || abs(y1 - y) > 8)
            **er = 5;
        break;
    case 3:
    case 30: // koni
        if (abs(x1 - x) > 8 || abs(y1 - y) > 8)
            **er = 5;
        if ((abs(y1 - y) == 2 && abs(x1 - x) == 1)
            || (abs(y1 - y) == 1 && abs(x1 - x) == 2)) {
        } else
            **er = 1;
        break;
    case 4:
    case 40: // slon
        if (abs(x1 - x) > 8 || abs(y1 - y) > 8)
            **er = 5;
        if ((abs(x1 - x) > 0 && abs(y1 - y) == 0)
            || ((y1 - y) > 0 && (x1 - x) == 0))
            **er = 1;
        break;
    case 5:
    case 50: // ferz
        if (abs(x1 - x) > 8 || abs(y1 - y) > 8)
            **er = 5;
        if ((abs(x1 - x) == 2 && abs(y1 - y) == 1)
            || (abs(x1 - x) == 1 && abs(y1 - y) == 2))
            **er = 1;
        break;
    case 6:
    case 60: // korol
        if (abs(x1 - x) > 8 || abs(y1 - y) > 8)
            **er = 5;
        if (abs(x1 - x) > 1 && abs(y1 - y) > 1)
            **er = 1;
        break;
    }
}

void move(int hod, char text[], int pole[Weight][Height], int* er, FILE* ofile)
{ //[1] - strochka [2] - stolbik
    int znak = 0, znak1 = 0, znak2 = 0;
    int xx = 0, yy = 0, xx1 = 0, yy1 = 0, flag = 0, pamat = 0, ned = 0,
        eflag = 0, pflag = 0, ochered = 0;
    for (znak = 0; znak < 20; znak++) {
        if (((text[znak] >= 73 && text[znak] <= 90) && text[znak] != 75
             && text[znak] != 78 && text[znak] != 80 && text[znak] != 81
             && text[znak] != 82)
            || (text[znak] >= 105 && text[znak] <= 122 && text[znak] != 120)
            || (text[znak] == 57)) {
            *er = 5;
            break;
        }

        if (text[znak] == '-')
            flag = 1;
        if (text[znak] == 'x')
            flag = 2;
        if (text[znak] == 'a' && flag == 0)
            xx = 0;
        else if (text[znak] == 'b' && flag == 0)
            xx = 1;
        else if (text[znak] == 'c' && flag == 0)
            xx = 2;
        else if (text[znak] == 'd' && flag == 0)
            xx = 3;
        else if (text[znak] == 'e' && flag == 0)
            xx = 4;
        else if (text[znak] == 'f' && flag == 0)
            xx = 5;
        else if (text[znak] == 'g' && flag == 0)
            xx = 6;
        else if (text[znak] == 'h' && flag == 0)
            xx = 7;
        else if (text[znak] == 49 && flag == 0)
            yy = 0;
        else if (text[znak] == 50 && flag == 0)
            yy = 1;
        else if (text[znak] == 51 && flag == 0)
            yy = 2;
        else if (text[znak] == 52 && flag == 0)
            yy = 3;
        else if (text[znak] == 53 && flag == 0)
            yy = 4;
        else if (text[znak] == 54 && flag == 0)
            yy = 5;
        else if (text[znak] == 55 && flag == 0)
            yy = 6;
        else if (text[znak] == 56 && flag == 0)
            yy = 7;

        if (text[znak] == 'a' && (flag == 1 || flag == 2))
            xx1 = 0;
        else if (text[znak] == 'b' && (flag == 1 || flag == 2))
            xx1 = 1;
        else if (text[znak] == 'c' && (flag == 1 || flag == 2))
            xx1 = 2;
        else if (text[znak] == 'd' && (flag == 1 || flag == 2))
            xx1 = 3;
        else if (text[znak] == 'e' && (flag == 1 || flag == 2))
            xx1 = 4;
        else if (text[znak] == 'f' && (flag == 1 || flag == 2))
            xx1 = 5;
        else if (text[znak] == 'g' && (flag == 1 || flag == 2))
            xx1 = 6;
        else if (text[znak] == 'h' && (flag == 1 || flag == 2))
            xx1 = 7;
        else if (text[znak] == 49 && (flag == 1 || flag == 2)) {
            yy1 = 0;
            eflag = 1;
        } else if (text[znak] == 50 && (flag == 1 || flag == 2)) {
            yy1 = 1;
            eflag = 1;
        } else if (text[znak] == 51 && (flag == 1 || flag == 2)) {
            yy1 = 2;
            eflag = 1;
        } else if (text[znak] == 52 && (flag == 1 || flag == 2)) {
            yy1 = 3;
            eflag = 1;
        } else if (text[znak] == 53 && (flag == 1 || flag == 2)) {
            yy1 = 4;
            eflag = 1;
        } else if (text[znak] == 54 && (flag == 1 || flag == 2)) {
            yy1 = 5;
            eflag = 1;
        } else if (text[znak] == 55 && (flag == 1 || flag == 2)) {
            yy1 = 6;
            eflag = 1;
        } else if (text[znak] == 56 && (flag == 1 || flag == 2)) {
            yy1 = 7;
            eflag = 1;
        }

        if (text[znak] == 'R' && flag == 0)
            ned = 20;
        else if (text[znak] == 'N' && flag == 0)
            ned = 30;
        else if (text[znak] == 'B' && flag == 0)
            ned = 40;
        else if (text[znak] == 'Q' && flag == 0)
            ned = 50;
        else if (text[znak] == 'K' && flag == 0)
            ned = 60;

        if (text[znak] != ' ' && text[znak] != '.' && pflag == 0) {
            znak1 = znak;
            pflag = 1;
        }

        if (eflag == 1 && flag == 1) {
            znak2 = znak;
            if (ned > 0
                && (pole[yy][xx] != ned && pole[yy][xx] != (ned / 10))) {
                *er = 2;
                break;
            }
            if (pole[yy1][xx1] != 0) {
                *er = 3;
                break;
            }
            checkrule(hod, xx, yy, xx1, yy1, flag, pole[yy][xx], &er);
            pamat = pole[yy][xx];
            pole[yy][xx] = 0;
            pole[yy1][xx1] = pamat;
            flag = 3;
            printtable(hod, text, znak1, znak2, pole, ofile);
            if (pole[yy1][xx1] <= 6 && (ochered == 0 || ochered == 2))
                ochered = 1;
            else if (
                    pole[yy1][xx1] >= 10 && pole[yy1][xx1] <= 60
                    && ochered == 1)
                ochered = 2;
            else
                *er = 6;
        }
        if (eflag == 1 && flag == 2) {
            znak2 = znak;
            if (ned > 0
                && (pole[yy][xx] != ned && pole[yy][xx] != (ned / 10))) {
                *er = 2;
                break;
            }
            if (pole[yy1][xx1] == 0) {
                *er = 4;
                break;
            }
            checkrule(hod, xx, yy, xx1, yy1, flag, pole[yy][xx], &er);
            pamat = pole[yy][xx];
            pole[yy][xx] = 0;
            pole[yy1][xx1] = pamat;
            flag = 3;
            printtable(hod, text, znak1, znak2, pole, ofile);
            if (pole[yy1][xx1] <= 6 && (ochered == 0 || ochered == 2))
                ochered = 1;
            else if (
                    pole[yy1][xx1] >= 10 && pole[yy1][xx1] <= 60
                    && ochered == 1)
                ochered = 2;
            else
                *er = 6;
        }

        if (text[znak] == 35 || text[znak] == '+') {
            break;
        }

        if (flag == 3) {
            flag = 0;
            eflag = 0;
            pflag = 0;
            ned = 0;
            xx = 0;
            yy = 0;
            pamat = 0;
            xx1 = 0;
            yy1 = 0;
        }

        if (*er > 0)
            break;
    }
}

void erormes(int* er, FILE* ofile)
{
    switch (*er) {
    case 1:
        printf(" \nViolation of the rules for the movement of figures.\n ");
        fprintf(ofile,
                " \nViolation of the rules for the movement of figures.\n ");
        break;
    case 2:
        printf(" \nThe piece that was supposed to move was not in "
               "position.\n ");
        fprintf(ofile,
                " \nThe piece that was supposed to move was not in "
                "position.\n ");
        break;
    case 3:
        printf(" \nWith a quiet move, a figure appeared on the way.\n ");
        fprintf(ofile,
                " \nWith a quiet move, a figure appeared on the way.\n ");
        break;
    case 4:
        printf(" \nWhen capturing, there was no piece to capture.\n ");
        fprintf(ofile, " \nWhen capturing, there was no piece to capture.\n ");
        break;
    case 5:
        printf(" \nExceeding the field boundaries or non-existent "
               "position.\n ");
        fprintf(ofile,
                " \nExceeding the field boundaries or non-existent "
                "position.\n ");
        break;
    case 6:
        printf(" \nThe sequence of moves is broken.\n ");
        fprintf(ofile, " \nThe sequence of moves is broken.\n ");
        break;
    default:
        printf(" \nThe party is over. There are no errors.\n ");
        fprintf(ofile, " \nThe party is over. There are no errors.\n ");
        break;
    }
}

int main()
{
    int ex = 0, c = 0, er = 0, hod = 1;
    int tab[Weight][Height];
    char line[20];

    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error. Text file do not opened. Check text.txt file.");
        return -3;
    }

    FILE* ofile = fopen("output.txt", "w");
    if (ofile == NULL) {
        printf(" Errore. Output file do not opened. Check output.txt file. ");
        return -3;
    }

    starttable(tab);
    printtable(0, line, 0, 0, tab, ofile);
    printf("\n \n");
    fprintf(ofile, "\n \n");
    while (ex < 2) {
        while ((c = fgetc(file)) != EOF) {
            fgets(line, 20, file);
            move(hod, line, tab, &er, ofile);
            printf("\n \n");
            fprintf(ofile, "\n \n");
            hod++;
            if (er > 0)
                break;
        }
        erormes(&er, ofile);
        if (er > 0) {
            return -3;
        }
        ex += 20;
    }
    fclose(file);
    fclose(ofile);
    return 0;
}

