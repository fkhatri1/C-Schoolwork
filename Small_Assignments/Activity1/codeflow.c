#include <stdio.h>

int main() {
  #define LOWER 1
  #define UPPER 50

  int i;
  int c = 0;

  while (c<LOWER || c>UPPER) {
    scanf("%d", &c);
  }
  
  for (i=0; i<=c; i++) {
    if ( (i%4 == 0) && (i%8 == 0) ) {
      printf ("%d:\tffffseven\n", i);
    } 
    else if (i%7 == 0) {
      printf ("%d:\tseven\n", i);
    }
    else if (i%4 == 0) {
      printf ("%d:\tffff \n", i);
    }
    else if (i%5 == 0) {
      printf ("%d:\t \n", i);
    }  
    else {
      printf ("%d:\t%d\n", i, i);
    }
  }

  return 0;
}
