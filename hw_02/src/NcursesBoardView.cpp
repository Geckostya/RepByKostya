#include "NcursesBoardView.h"

NcursesBoardView::NcursesBoardView(Board& b): board(b) {
}

void NcursesBoardView::show_board() {
	int h = board.get_height();
	int w = board.get_width();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			switch (board.get_cell(i, j)) {
				case cell_free: 
					mvprintw(i, j, ".");
				break;

				case cell_X:
					mvprintw(i, j, "X");
				break;

				case cell_O:
					mvprintw(i, j, "O");
				break;
			}
	}
}

bool NcursesBoardView::get_input(int& x, int& y, cell_status to_cell){
	move(y, x);

	while(true) {
		int key = getch();

		switch(key) {
			case down_key: 
				if (y < board.get_height() - 1)
					move(++y, x);
			break;
			
			case up_key:
				if (y > 0)
					move(--y, x);
			break;

			case left_key:
				if (x > 0)
					move(y, --x);
			break;

			case right_key:
				if (x < board.get_width() - 1)
					move(y, ++x);
			break;

			case space_key:
				if (board.can_move(x, y, to_cell)){
					move (board.get_height() + 1, 0);
					clrtoeol();
					move(y, x);
					return true;
				}
			break;

			case save_key:{
					if (board.save_game())
						mvprintw(board.get_height() + 1, 0, "Game saved     ");
					else
						mvprintw(board.get_height() + 1, 0, "Can't save game    ");
					
					move(y, x);
				}
			break;

			case load_key:{
				if (board.load_game()){
					clear();
					show_board();
					mvprintw(board.get_height() + 1, 0, "Game loaded     ");
				} else
					mvprintw(board.get_height() + 1, 0, "Can't load game    ");

				move(y, x);
			}
			break;

			case x_key: {
				endwin();
				return false;
			}
		}
	}

	return true;
}

void NcursesBoardView::do_game_cycle() {
	int playerX = 0;
	initscr();
	keypad(stdscr, true);
	raw();
	noecho();

	int x = 0, y = 0;
	show_board();

	while(true) {		
		char sign = 'O';
		if (playerX)
			sign = 'X';

		cell_status to_cell = cell_O;
		if (playerX)
			to_cell = cell_X;
		
		if (!get_input(x, y, to_cell))
			return;

		board.move(x, y, to_cell);
		printw("%c", sign);

		game_status check = board.is_win(x, y);

		switch (check) {
			case game_win: {
				mvprintw(board.get_height(), 0, "%c wins!", sign);
				getch();
				endwin();
				return;
			};
			break;

			case game_draw: {
				mvprintw(board.get_height(), 0, "Draw.");
				getch();
				endwin();
				return;
			};
			break;

			default:
				playerX = ~playerX;
		}
	}
} 