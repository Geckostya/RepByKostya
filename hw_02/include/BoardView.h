#pragma once
#include "Board.h"
#include <cstdio>
#include <string.h>
#include <stdio.h>

class BoardView {
private:
	Board& board;
	bool silence;
public:
    BoardView(Board &b):board(b){ silence = 0;}
    void set_silence(bool is_silent);
    void show_board();
    void do_game_cycle();
    bool get_input(int& x, int& y, char sign, cell_status to_cell);
    void try_read(int& x, int& y);
};