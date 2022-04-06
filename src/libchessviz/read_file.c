#include <libchessviz/move.h>
#include <libchessviz/read_file.h>

void read_file(
        int step,
        char text[],
        FILE* ofile,
        int* error,
        int table[Weight][Height])
{
    int xx = 0, yy = 0, xx1 = 0, yy1 = 0, move_flag = 0, need_figure = 0,
        end_of_record = 0, print_flag = 0, first_sign = 0, last_sign = 0, players_turn=0;

    for (int symbol = 0; symbol <= (int)strlen(text) - reading_artifacts; symbol++) {
        if ((int)text[symbol] != 23 && (int)text[symbol] != 43
            && (int)text[symbol] != 45 && (int)text[symbol] != 46
            && (int)text[symbol] != 49 && (int)text[symbol] != 50
            && (int)text[symbol] != 51 && (int)text[symbol] != 52
            && (int)text[symbol] != 53 && (int)text[symbol] != 54
            && (int)text[symbol] != 55 && (int)text[symbol] != 56
            && (int)text[symbol] != 97 && (int)text[symbol] != 98
            && (int)text[symbol] != 99 && (int)text[symbol] != 100
            && (int)text[symbol] != 101 && (int)text[symbol] != 102
            && (int)text[symbol] != 103 && (int)text[symbol] != 104
            && (int)text[symbol] != 75 && (int)text[symbol] != 81
            && (int)text[symbol] != 82 && (int)text[symbol] != 66
            && (int)text[symbol] != 78 && (int)text[symbol] != 112
            && (int)text[symbol] != 32 && (int)text[symbol] != 120) {
            *error = 5;
            break;
        }

        if (text[symbol] == '-')
            move_flag = 1;
        if (text[symbol] == 'x')
            move_flag = 2;
        if (text[symbol] == 'a' && move_flag == 0)
            xx = 0;
        else if (text[symbol] == 'b' && move_flag == 0)
            xx = 1;
        else if (text[symbol] == 'c' && move_flag == 0)
            xx = 2;
        else if (text[symbol] == 'd' && move_flag == 0)
            xx = 3;
        else if (text[symbol] == 'e' && move_flag == 0)
            xx = 4;
        else if (text[symbol] == 'f' && move_flag == 0)
            xx = 5;
        else if (text[symbol] == 'g' && move_flag == 0)
            xx = 6;
        else if (text[symbol] == 'h' && move_flag == 0)
            xx = 7;
        else if (text[symbol] == '1' && move_flag == 0)
            yy = 0;
        else if (text[symbol] == '2' && move_flag == 0)
            yy = 1;
        else if (text[symbol] == '3' && move_flag == 0)
            yy = 2;
        else if (text[symbol] == '4' && move_flag == 0)
            yy = 3;
        else if (text[symbol] == '5' && move_flag == 0)
            yy = 4;
        else if (text[symbol] == '6' && move_flag == 0)
            yy = 5;
        else if (text[symbol] == '7' && move_flag == 0)
            yy = 6;
        else if (text[symbol] == '8' && move_flag == 0)
            yy = 7;

        if (text[symbol] == 'a' && (move_flag == 1 || move_flag == 2))
            xx1 = 0;
        else if (text[symbol] == 'b' && (move_flag == 1 || move_flag == 2))
            xx1 = 1;
        else if (text[symbol] == 'c' && (move_flag == 1 || move_flag == 2))
            xx1 = 2;
        else if (text[symbol] == 'd' && (move_flag == 1 || move_flag == 2))
            xx1 = 3;
        else if (text[symbol] == 'e' && (move_flag == 1 || move_flag == 2))
            xx1 = 4;
        else if (text[symbol] == 'f' && (move_flag == 1 || move_flag == 2))
            xx1 = 5;
        else if (text[symbol] == 'g' && (move_flag == 1 || move_flag == 2))
            xx1 = 6;
        else if (text[symbol] == 'h' && (move_flag == 1 || move_flag == 2))
            xx1 = 7;
        else if (text[symbol] == '1' && (move_flag == 1 || move_flag == 2)) {
            yy1 = 0;
            end_of_record = 1;
        } else if (text[symbol] == '2' && (move_flag == 1 || move_flag == 2)) {
            yy1 = 1;
            end_of_record = 1;
        } else if (text[symbol] == '3' && (move_flag == 1 || move_flag == 2)) {
            yy1 = 2;
            end_of_record = 1;
        } else if (text[symbol] == '4' && (move_flag == 1 || move_flag == 2)) {
            yy1 = 3;
            end_of_record = 1;
        } else if (text[symbol] == '5' && (move_flag == 1 || move_flag == 2)) {
            yy1 = 4;
            end_of_record = 1;
        } else if (text[symbol] == '6' && (move_flag == 1 || move_flag == 2)) {
            yy1 = 5;
            end_of_record = 1;
        } else if (text[symbol] == '7' && (move_flag == 1 || move_flag == 2)) {
            yy1 = 6;
            end_of_record = 1;
        } else if (text[symbol] == '8' && (move_flag == 1 || move_flag == 2)) {
            yy1 = 7;
            end_of_record = 1;
        }

        if (text[symbol] == 'R' && move_flag == 0)
            need_figure = 20;
        else if (text[symbol] == 'N' && move_flag == 0)
            need_figure = 30;
        else if (text[symbol] == 'B' && move_flag == 0)
            need_figure = 40;
        else if (text[symbol] == 'Q' && move_flag == 0)
            need_figure = 50;
        else if (text[symbol] == 'K' && move_flag == 0)
            need_figure = 60;

        if (text[symbol] != ' ' && text[symbol] != '.' && print_flag == 0) {
            first_sign = symbol;
            print_flag = 1;
        }

        if (text[symbol] == 35 || text[symbol] == '+') {
            break;
        }

        if (end_of_record == 1 && (move_flag == 1 || move_flag == 2)){
last_sign=symbol;           
 move_figure(
                    step,
                    xx,
                    yy,
                    xx1,
                    yy1,
                    &move_flag,
                    first_sign,
last_sign,
                    text,
                    // print_flag,
                    end_of_record,
                    need_figure,
&players_turn,
                   // symbol,
                    table,
                    error,
                    ofile);}

if (move_flag == 3) {
            move_flag = 0;
            end_of_record = 0;
            print_flag = 0;
            need_figure = 0;
            xx = 0;
            yy = 0;
            //memory = 0;
            xx1 = 0;
            yy1 = 0;
        }

        if (*error > 0)
            break;
    }
}
