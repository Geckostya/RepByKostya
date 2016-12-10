#include "Test.h"

void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
    if (!expr) {
        printf("“test failed: %s in %s:%i”\n", func, filename, (int)lineNum);
        Test::failedNum ++;
    }

    Test::totalNum++;
}

void Test::showFinalResult() {
    if (!Test::failedNum)
        printf("All test passed\n");
    else
        printf("failed %d of %d tests.\n", Test::failedNum, Test::totalNum);
}