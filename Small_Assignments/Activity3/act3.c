#include <stdio.h>
#include <string.h>

/*
  This file contains gcd(), remainder() and escape() methods.
*/

int gcd(int x, int y) {
  if (y == 0) {
    return x;
  }
  else if (y > 0) {
    return gcd(y, remainder(x, y));
  }
  else {
    return -1;
  }
}

int remainder(int x, int y) {
  return (x % y);
}


void escape(char s[]) {
  int i;
  int length = strlen(s);

  printf("\n***\nOriginal string: %s\n", s);
  printf("escape(s): ");

  for (i=0; i<length; i++) {
    switch (s[i]) {
      case '\n':
        printf ("\\n");
        break;
      case '\t':
        printf ("\\t");
        break;
      default: 
        printf ("%c", s[i]);
        break;
    }
  }
  printf("\n***\n");
}
