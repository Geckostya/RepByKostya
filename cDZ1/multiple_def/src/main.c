#include "../src/io.c"
#include "../include/util.h"
#include "../include/algorithm.h"
int main() {
  int a = doComputation(5, 7.0); 
  int b = 5;
  max(a, b);
  logDebug('!');
  return 0;
}
