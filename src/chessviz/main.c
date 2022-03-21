#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include <chessviz/start_table.h>
#include <libchessviz/check_rule.h>
#include <libchessviz/eror_mes.h>
#include <libchessviz/move.h>
#include <libchessviz/print_table.h>

#define Weight 8
#define Height 8

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
            return 44;
        }
        ex += 20;
    }
    fclose(file);
    fclose(ofile);
    return 0;
}
