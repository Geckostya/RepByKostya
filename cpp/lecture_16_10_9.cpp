Depends - зависит

Класс А зависит от класса В

A --------> B
   depends

class A
1. B obj*
2. B *pObj;
3. B &rObj;

Если я хочу использовать класс А в новой программе, то обязательно нужно перенести
в новый проект и класс B.

А так B так C так.
 ну  и потом вот так.


 Model-View

 Design Patterns. - это книга, которая пишет о том, как лучше что-то писать
 Если шаблоны проектирования использовать бездумно, там где это не сильно нужно, то
 программа будет очень бессмысленно сложной.

Model -> (Board) 
  	- Хранение в памяти
  	- Правила
View -> (TextView)
	- Вывод игрового поля
	- Ввод от пользователя

Controller.(но это нам не нужно)
	- пользование


Тут понятно, что VIEW менее универсален. Как мы можем его менять?
Можно для десктопа делать программу с красивым интерфейсом.
Можно сделать для телефона.
Можно сделать для веб.

TextView ------> Board
Внутри будет ссылка на Board.

class Board {
private:
	?

public:
	Board();
	//деструктор по усмотрению реализации
	void move(int x, int y, char c);
	bool can_move(int x, int y, char c) const;
	enum end_type game_end();
	int get_cell(int x, int y);
	int get_widgth();
	int get_height();

}

main(){
	Board b(...);
	TextView tv(b);
	tv.start_game_cycle;
	return 0;
}

class TextView {
private:
	Board &b;
	...
public:
	TextView(Board& board): b(Board){}
	void start_game_cycle(){
		//псевдокод
		while(b.game_end() == GAME_IN_PROGRESS){
			1. считать ход игрока x y// чтобы было правильно
			2. b.move(x, y, 'o');
			3. show_board
			4. game_end?
				break;
			1, 2, 3, 4 for 'x'
		}
	}
	void show_board(){
		for (i)
			for (j)
				printf + get_cell
	}
CorsesView
1. стрелочками двигатьсяя
2. чтобы была доска одна
stdio не даёт нам этой прелести

ncurses - позволяет. 
	expat
}

Автотесты
=========

static - вспомним это слово.
static - нужна чтобы вынести глобавльные переменные, но так, чтобы не было коллизии имён в разных файлах.

Я хочу завести счётчик в классе прямоугльника, чтобы у всех выбла одна переменная.

hpp.
Rectangle
	statin int num;
	Rectangle(){
		num++
	}
cpp.
int Rectangle::num=0;

main(){
	Rectangle r1;
	Rectangle r2;
	r2.num == 2
	Rectangle::num = 34;
}

то - статические переменные

Теперь нам понадобятся статические ф-ции

static bool cmp(Rectangle &r1, Rectangle &r2){
	//w = 3 нельзя так делать
}


достоинства автотестов:
1. повторимость
2. документация

test
	BoardTest.{cpp, hpp}
	test.cpp -> main()

Makefile
Make -> main.cpp
Make test -> test.cpp

#include "Board.h"
class BoardTest
testCanMove(){
	Board b;
	b.move(1,1,'x');
	bool res = b.can_move(1,1,'o');
	if (res)
		printf("test can move failed");
}

main(){
	BoardTest bt;
	bt.testCanMove();
	bt.testIsWin1();
	bt.testIsWin2();
	....
}

calss Test:
static total;
static failed;
static void show stat();
static void check(bool expr
const char* func, const char* file, int line){

	if (!expr){
		failed++;
		printf(bla bla file func line bla bla);
	total++;
}

check(res == false, "testCanMove", "Boardtest", 35)
__FUNC__ - имя ф-ции
__FILE__
__LINE__