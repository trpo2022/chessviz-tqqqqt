#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Weight 8
#define Height 8
#define reading_artifacts 2
#define size 40

#define Wait_mode 0
#define Party_over 1
#define Violation_of_rules 2
#define Piece_not_in_pos 3
#define Error_quite_move 4
#define Error_capture_move 5
#define Exceeding_field_bound 6
#define Broken_sequence_moves 7

void move_figure(
        int memory,
        int step,
        int xx,
        int yy,
        int xx1,
        int yy1,
        int* move_flag,
        int* first_sign,
        int* last_sign,
        char line[size],
        int end_of_record,
        int need_figure,
        int* player_turn,
        int table[Weight][Height],
        int* error,
        FILE* ofile);
