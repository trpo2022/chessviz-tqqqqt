#pragma once

#include <stdio.h>
#include <stdlib.h>

#define Wait_mode 0
#define Party_over 1
#define Violation_of_rules 2
#define Piece_not_in_pos 3
#define Error_quite_move 4
#define Error_capture_move 5
#define Exceeding_field_bound 6
#define Broken_sequence_moves 7

void eror_message(char* ErrorNam[], int* er, FILE* ofile);
