#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Weight 8
#define Height 8
#define reading_artifacts 2
#define size 40

void read_file(
        int step,
        char text[],
        FILE* ofile,
        int* error,
        int table[Weight][Height]);