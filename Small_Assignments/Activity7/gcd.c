#include <stdio.h>
#include <string.h>
#include "gcd.h"

/*
  This file contains gcd().
*/

int gcd(int x, int y) {
  if (y == 0) {
    return x;
  }
  else if (y > 0) {
    return gcd(y, x % y);
  }
  else {
    return -1;
  }
}