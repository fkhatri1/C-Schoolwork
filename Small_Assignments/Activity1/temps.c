#include<stdio.h>

/* symbolic constants */
#define LOWER 0
#define UPPER 100
#define STEP 10

int main() {
  double fahr;
  int celsius;

  for (celsius = LOWER; celsius <= UPPER; celsius+=STEP) {
    //celsius = 5.0 * (fahr - 32.0) / 9.0;
    fahr = celsius * 9 / 5 + 32;    

    /* 
        %4d - print an integer in a 4 character wide column
        \t - tab character
        %6.1 - print a floating point number with 1 decimal point
        \n - newline
    */
    printf("%4d\t%6.1f\n", celsius, fahr);
  } 
  return 0;
}
