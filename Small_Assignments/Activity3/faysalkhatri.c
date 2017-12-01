#include "act3.h"
#include "act3.c"

/*
  This file is a test driver for gcd(), remainder() and escape().
*/

int main() {
  printf("GCD of %d and %d is %d\n",10, 15, gcd(10, 15));
  printf("GCD of %d and %d is %d\n",80, 497, gcd(80, 497));
  printf("GCD of %d and %d is %d\n",99, 645, gcd(99, 645));

  escape("Test	this	string   ");
  escape("Hello world of 	tabs and new lines \n ");
  escape("Test more 	tabs  and spaces  and new lines \n	tab");
  return 0;

}
