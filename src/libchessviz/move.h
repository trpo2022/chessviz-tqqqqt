#pragma once

#include <stdio.h>
#include <stdlib.h>

#define Weight 8
#define Height 8
#define size 20

void move_figure(int step, char text[], int table[Weight][Height], int* error, FILE* ofile);
