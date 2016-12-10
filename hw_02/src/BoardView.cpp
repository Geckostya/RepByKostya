#include "BoardView.h"


void BoardView::set_silence(bool is_silent) {
	silence = is_silent;
}

void BoardView::show_board() {
	if (silence) return;
	int h = board.get_height();
	int w = board.get_widgth();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			switch (board.get_cell(i, j)) {
				case cell_free : printf(".");
				break;
				case cell_X    : printf("X");
				break;
				case cell_O    : printf("O");
				break;
			}
		printf("\n");
	}
}

void BoardView::do_game_cycle() {
	int playerX = 0;

	while(true) {
		show_board();
		char sign = 'O';
		if (playerX)
			sign = 'X';

		cell_status to_cell = cell_O;
		if (playerX)
			to_cell = cell_X;

		int x, y;
		while(true) {
			printf("%c move: ", sign);
			if(scanf("%d %d", &x, &y) != 2) {
				printf("What are hell is going on?\n");
				return;
			}

			if (x == -1 && y == -1)
				return;

			if (board.can_move(x, y, to_cell))
				break;
		}

		board.move(x, y, to_cell);

		game_status check = board.is_win();
		switch (check){
			case game_win: {

				silence = false;
				show_board();

				if (playerX)
					printf("X");
				else
					printf("O");

				printf(" wins!\n");
				return;
			};
			break;

			case game_draw: {
				printf("Draw.\n");
				return;
			};
			break;

			default: playerX = ~playerX;
		}
	}
} 