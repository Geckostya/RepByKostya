#include "Board.h"

void Board::create_board(){
	board = new cell_status*[height];
	board[0] = new cell_status[height * width];
	std::fill(board[0], board[0] + height * width, cell_free);
	for (int i = 0; i < height; i++)
		board[i] = board[0] + i * width;
}

void Board::delete_board(){
	delete[] board[0];
	delete[] board;
}

Board::Board(int h, int w) {
	if (h < 5)
		h = 5;
	if (w < 5)
		w = 5;

	used_cells = 0;

	height = h;
	width = w;

	create_board();
}

Board::~Board() {
	delete_board();
}

int Board::save_game(){
	FILE* f = fopen("saved_game", "wb");
	if (f == NULL)
		return 0;

	fwrite(&height, sizeof(int32_t), 1, f);
	fwrite(&width, sizeof(int32_t), 1, f);
	fwrite(&used_cells, sizeof(int32_t), 1, f);

	fwrite(board[0], sizeof(cell_status), height*width, f);


	fclose(f);
	return 1;
}

int Board::load_game(){
	FILE* f = fopen("saved_game", "rb");
	if (f == NULL)
		return 0;

	fread(&height, sizeof(int32_t), 1, f);
	fread(&width, sizeof(int32_t), 1, f);
	fread(&used_cells, sizeof(int32_t), 1, f);

	delete_board();
	create_board();

	fread(board[0], sizeof(cell_status), height*width, f);
	fclose(f);
	return 1;
}

void Board::move(int x, int y, cell_status sign) {
	board[y][x] = sign;
	used_cells++; 
}

bool Board::can_move(int x, int y, cell_status sign) const {
	if (sign == cell_free)
		return false;

	if (x >= width || x < 0 ||
		y >= height || y < 0)
		return false;

	if (board[y][x] != cell_free)
		return false;

	return true;

}

void Board::check_cell(int x, int y, cell_status cur_cell, char& value){
	if (x >= 0 && x < width && y >= 0 && y < height){
		if (board[y][x] == cur_cell)
			value++;
		else
			value = 0;
	}
}

game_status Board::is_win(int x, int y) {
	if (used_cells >= width * height)
		return game_draw;

	cell_status cur_cell = board[y][x];

	result check;
	check = 0;

	for (int i = -4; i < 5; i++){
		check_cell(x + i, y, cur_cell, check.horizontal);
		
		check_cell(x, y + i, cur_cell, check.vertical);
		
		check_cell(x + i, y + i, cur_cell, check.first_diag);
		
		check_cell(x - i, y + i, cur_cell, check.second_diag);

		if (check == 5)
			return game_win;
	}

	return game_in_progress;
}

cell_status Board::get_cell(int i, int j) const {
	return board[i][j];
}

int Board::get_width() const {
	return width;
}

int Board::get_height() const {
	return height;
}