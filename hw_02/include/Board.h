#pragma once
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

enum game_status{game_win, game_in_progress, game_draw};
enum cell_status{cell_free, cell_X, cell_O};

struct result{
	char horizontal, vertical, first_diag, second_diag;
	char operator=(char i){
		horizontal = i;
		vertical = i;
		first_diag = i;
		second_diag = i;
		return i;
	}

	bool operator==(char i){
		return (horizontal == i || vertical == i ||
				first_diag == i || second_diag == i);
	}
	
};

class  Board {
private:
	cell_status** board;
	int32_t width;
	int32_t height;
	int32_t used_cells;

public:
	Board(int h = 10, int w = 10);
	~Board();
    void move(int x, int y, cell_status sign); //сделать ход
    bool can_move(int x, int y, cell_status sign) const; //корректен ли ход
    
    int save_game();
    int load_game();

    void create_board();
    void delete_board();

    void check_cell(int x, int y, cell_status cur_cell, char& value);
    game_status is_win(int x, int y); // текущее состояние: играем дальше; ничья; 0 выиграли; X выиграли
    cell_status get_cell(int i, int j) const;

	int get_width() const;
	int get_height() const;
    //Можно добавлять методы при необходимости.
};