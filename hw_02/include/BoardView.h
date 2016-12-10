#pragma once
#include "Board.h"
#include <cstdio>

class BoardView {
private:
	Board& board;
	bool silence;
public:
    BoardView(Board &b):board(b){ silence = 0;}
    void set_silence(bool is_silent);
    void show_board();
    void do_game_cycle(); 
};