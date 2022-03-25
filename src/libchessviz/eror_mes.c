#include <libchessviz/eror_mes.h>

void eror_message(int* error, FILE* ofile)
{
    switch (*error) {
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
