#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Weight 8
#define Height 8
#define reading_artifacts 2
#define size 40

void move_figure(
        int step,
        char text[],
        int table[Weight][Height],
        int* error,
        FILE* ofile);
