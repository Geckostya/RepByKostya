#include "BoardTest.h"

void BoardTest::testIsWin1() {
    Board b;
    b.move(0, 0, cell_X);
    b.move(0, 1, cell_X);
    b.move(1, 0, cell_X);
    b.move(4, 5, cell_O);
    b.move(5, 5, cell_O);
    DO_CHECK(b.is_win() == game_in_progress);
}

void BoardTest::testIsWin2() {
    Board b;
    b.move(0, 0, cell_X);
    b.move(0, 1, cell_X);
    b.move(0, 2, cell_X);
    b.move(0, 3, cell_X);
    b.move(0, 4, cell_X);
    DO_CHECK(b.is_win() == game_win);
}

void BoardTest::testIsWin3() {
    Board b;
    b.move(0, 0, cell_O);
    b.move(1, 1, cell_O);
    b.move(2, 2, cell_O);
    b.move(3, 3, cell_O);
    b.move(4, 4, cell_O);
    DO_CHECK(b.is_win() == game_win);
}


void BoardTest::testMove1() {
    Board b;
    b.move(0, 0, cell_O);
    DO_CHECK(b.can_move(0, 0, cell_X) == false);
}

void BoardTest::testMove2() {
    Board b;
    b.move(0, 0, cell_O);
    DO_CHECK(b.get_cell(0, 0) == cell_O);
}

void BoardTest::testMove3() {
    Board b;
    b.move(2, 4, cell_X);
    DO_CHECK(b.get_cell(4, 2) == cell_X);
}

void BoardTest::testCanMove1() {
    Board b;
    DO_CHECK(b.can_move(0, 0, cell_X) == true);
}

void BoardTest::testCanMove2() {
    Board b;
    DO_CHECK(b.can_move(-1, 0, cell_X) == false);
}

void BoardTest::testCanMove3() {
    Board b;
    b.move(0, 0, cell_X);
    DO_CHECK(b.can_move(0, 0, cell_X) == false);
}

void BoardTest::runAllTests() {
    testIsWin1();
    testIsWin2();
    testIsWin3();

    testMove1();
    testMove2();
    testMove3();

    testCanMove1();
    testCanMove2();
    testCanMove3();
}