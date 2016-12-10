#include "NcursesBoardView.h"

NcursesBoardView::NcursesBoardView(Board& b): board(b) {
}

void NcursesBoardView::show_board() {
	int h = board.get_height();
	int w = board.get_widgth();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			switch (board.get_cell(i, j)) {
				case cell_free : mvprintw(i, j, ".");
				break;
				case cell_X    : mvprintw(i, j, "X");
				break;
				case cell_O    : mvprintw(i, j, "O");
				break;
			}
	}
}

void NcursesBoardView::do_game_cycle() {
	int playerX = 0;
	initscr();
	keypad(stdscr, true);
	noecho();
	//printw("hello");
	//win = newwin(11, 10, 10, 10);
	//wrefresh(win);
	//wprintw(win, "how are you?");
	int x = 0, y = 0;
	int height = board.get_height();
	int widgth = board.get_widgth();
	
	show_board();

	while(true) {		
		char sign = 'O';
		if (playerX)
			sign = 'X';

		cell_status to_cell = cell_O;
		if (playerX)
			to_cell = cell_X;

		int c;
		bool waiting = true;
		move(y, x);

		while(waiting){
			c = getch();
			switch(c){
				case down_key: 
					if (y < height - 1)
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
					if (x < widgth - 1)
						move(y, ++x);
				break;

				case space_key:{
					if (board.can_move(x, y, to_cell))
						waiting = false;
				}
				break;

				case x_key:{
					endwin();
					return;
				}
			}
		}
	

		board.move(x, y, to_cell);
		printw("%c", sign);

		game_status check = board.is_win();

		switch (check) {
			case game_win: {
				mvprintw( 10, 0, "%c wins!", sign);
				getch();
				endwin();
				return;
			};
			break;

			case game_draw: {
				mvprintw(10, 0, "Draw.");
				getch();
				endwin();
				return;
			};
			break;

			default: playerX = ~playerX;
		}
	}
} 