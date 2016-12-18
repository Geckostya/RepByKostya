#pragma once
#include "Board.h"
#include "ncurses.h"

enum game_keys{down_key = 258, up_key, left_key, right_key, space_key = 32,
			   x_key = 120, save_key = 19, load_key = 12};

class NcursesBoardView {
private:
	Board& board;
public:
	NcursesBoardView(Board& b);
    void show_board();
    bool get_input(int& x, int& y, cell_status to_cell);
    void do_game_cycle(); 
};