#include <libchessviz/eror_mes.h>

void eror_message(char* ErrorNam[], int* error, FILE* ofile)
{
    if (*error == Wait_mode || *error == Party_over) {
        puts(ErrorNam[*error]);
        fputs(ErrorNam[*error], ofile);
    } else {
        puts(ErrorNam[*error - 1]);
        fputs(ErrorNam[*error - 1], ofile);
    }
}
