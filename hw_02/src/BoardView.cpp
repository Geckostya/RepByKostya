#include "BoardView.h"


void BoardView::set_silence(bool is_silent) {
	silence = is_silent;
}

void BoardView::show_board() {
	if (silence)
		return;
	
	printf("\n");
	int h = board.get_height();
	int w = board.get_width();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			switch (board.get_cell(i, j)) {
				case cell_free:
					printf(".");
				break;

				case cell_X:
					printf("X");
				break;

				case cell_O:
					printf("O");
				break;
			}
		printf("\n");
	}
}

void BoardView::try_read(int& x, int& y){
	char buff[256];
	char* unused;

	unused = fgets(buff, 256, stdin);
	(void) unused;

	int len = strlen(buff);

	char* str = new char[len];
	strcpy(str, buff);
	str[len-1] = 0;

	if (sscanf(str, "%d %d", &y, &x) != 2)
		x = -666;

	if (strcmp(str, "exit") == 0)
		x = -1, y = -1;

	if (strcmp(str, "save") == 0)
		x = -2, y = -2;

	if (strcmp(str, "load") == 0)
		x = -3, y = -3;

}

bool BoardView::get_input(int& x, int& y, char sign, cell_status to_cell){
	while(true) {
			printf("%c move: ", sign);
			try_read(x, y);

			if (x == -1 && y == -1)
				return false;

			if (x == -2 && y == -2){
				if (board.save_game())
					printf("Game saved\n\n");
				else
					printf("Can't save game\n\n");
				continue;
			}

			if (x == -3 && y == -3){
				if (board.load_game())
					printf("Game loaded\n");
				else
					printf("Can't load game\n");
				show_board();
				continue;
			}

			if (board.can_move(x, y, to_cell)){
				return true;
			} else
				printf("Bad move!\n");
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
		if(!get_input(x, y, sign, to_cell))
			return;

		board.move(x, y, to_cell);

		game_status check = board.is_win(x, y);
		switch (check){
			case game_win: {
				silence = false;
				show_board();

				printf("%c wins!\n", sign);
				return;
			}
			break;

			case game_draw: {
				printf("Draw.\n");
				return;
			}
			break;

			default:
				playerX = ~playerX;
		}
	}
} 