#pragma once
#include "Test.h"
#include "Board.h"
#define DO_CHECK(EXPR) check(EXPR, __FUNC__, __FILE__, __LINE__);

class BoardTest: public Test {
public:
    void testIsWin1();
    void testIsWin2();
    void testIsWin3();

    void testMove1();
    void testMove2();
    void testMove3();

    void testCanMove1();
    void testCanMove2();
    void testCanMove3();

    void runAllTests();
};