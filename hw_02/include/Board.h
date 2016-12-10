#pragma once
#include <algorithm>

enum game_status{game_win, game_in_progress, game_draw};
enum cell_status{cell_free, cell_X, cell_O};

struct res{
	char h, v, d1, d2;
	int operator=(int i){
		h = i;
		v = i;
		d1 = i;
		d2 = i;
		return i;
	}
};

class  Board {
private:
	cell_status** board;
	res** result;
	int widgth;
	int height;

public:
	Board(int h = 10, int w = 10);
	~Board();
    void move(int x, int y, cell_status sign); //сделать ход
    bool can_move(int x, int y, cell_status sign) const; //корректен ли ход
    
    game_status is_win(); // текущее состояние: играем дальше; ничья; 0 выиграли; X выиграли
    cell_status get_cell(int x, int y) const;

	int get_widgth() const;
	int get_height() const;
    //Можно добавлять методы при необходимости.
};