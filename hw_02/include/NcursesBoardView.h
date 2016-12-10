#pragma once
#include "Board.h"
#include "ncurses.h"

enum game_keys{down_key = 258, up_key, left_key, right_key, space_key = 32, x_key = 120};

class NcursesBoardView {
private:
	Board& board;
	WINDOW* win;
public:
	NcursesBoardView(Board& b);
    void show_board();
    void do_game_cycle(); 
};