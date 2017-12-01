#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gcd.h"

int x;
int y;

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf (stderr, "Invalid number of parameters.\n");
    return 0;
  }
  else {
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    if ( (x == 0) || (y == 0) ) {
      fprintf (stderr, "Non-numeric parameters.\n");
      return 0;
    }
    else {
     fprintf (stdout, "%d\n", gcd(x, y));
     return gcd(x, y);
    }
  }
}
  
