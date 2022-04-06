#include <stdio.h>
#include <stdlib.h>

#include <chessviz/start_table.h>
#include <libchessviz/check_rule.h>
#include <libchessviz/eror_mes.h>
#include <libchessviz/move.h>
#include <libchessviz/print_table.h>
#include <libchessviz/read_file.h>

#define Weight 8
#define Height 8
#define size 40

int main()
{
    int exit_status = 0, end_of_line = 0, error = 0, step = 1;
    int table[Weight][Height];
    char line[size];

    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error. Text file do not opened. Check text.txt file.");
        return 44;
    }

    FILE* ofile = fopen("output.txt", "r");
    if (ofile != NULL) {
        fclose(ofile);
        ofile = fopen("output.txt", "w");
        if (ofile == NULL)
            while (ofile == NULL)
                ofile = fopen("output.txt", "w");
    } else if (ofile == NULL) {
        ofile = fopen("output.txt", "w");
        if (ofile == NULL)
            while (ofile == NULL)
                ofile = fopen("output.txt", "w");
    }

    start_table(table);
    print_table(0, line, 0, 0, table, ofile);
    printf("\n \n");
    fprintf(ofile, "\n \n");
    while (exit_status < 2) {
        while ((end_of_line = fgetc(file)) != EOF) {
            fgets(line, size, file);
            read_file(step, line, ofile, &error, table);
            printf("\n \n");
            fprintf(ofile, "\n \n");
            step++;
            if (error > 0)
                break;
        }
        eror_message(&error, ofile);
        if (error > 0) {
            return 44;
        }
        exit_status += 20;
    }
    fclose(file);
    fclose(ofile);
    return 0;
}
