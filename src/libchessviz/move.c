#include <libchessviz/check_rule.h>
#include <libchessviz/move.h>
#include <libchessviz/print_table.h>

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

