#include "Board.h"
#include "BoardView.h"
#include <string.h>

int main(int argc, char**argv) {

	Board b;
	BoardView bv(b);

	if (argc > 1 && strcmp(argv[1], "silent") == 0)
		bv.set_silence(true);

	bv.do_game_cycle();
	
	return 0;
}