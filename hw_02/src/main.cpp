#include "Board.h"
#include "BoardView.h"
#include "NcursesBoardView.h"
#include <string.h>

int main(int argc, char** argv) {

	int height = 10;
	int width = 10;

	if (argc>2 && strcmp(argv[2], "settings") == 0) {
		printf("Write height: ");
		if (scanf("%d", &height) != 1) {
			printf("Oh no, wrong input\n");
			return 0;
		}
		
		printf("Write width: ");
		if (scanf("%d", &width) != 1) {
			printf("Oh no, wrong input\n");
			return 0;
		}
	}

	Board board(height, width);

	if (argc > 1 && strcmp(argv[1], "curses") == 0) {
		NcursesBoardView nbv(board);
		nbv.do_game_cycle();
		return 0;
	}
	

	BoardView bv(board);

	if (argc > 1 && strcmp(argv[1], "silent") == 0)
		bv.set_silence(true);

	bv.do_game_cycle();

	
	return 0;
}