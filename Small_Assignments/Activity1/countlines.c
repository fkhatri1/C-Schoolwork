#include <stdio.h>

int main() {
  int c;
  int nl=0;
  int t=0;
  int s=0;
  int digits[10];
  int i;
	
  /* initializing digits array to zero */

  for (i=0; i<10; i++) {
    digits[i] = 0;
  }

  while ( (c = getchar()) != EOF) {
    switch (c) {
      case '\n':
        nl++;
        break;
      case '\t':
        t++;
        break;
      case ' ':
        s++;
        break;
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        digits[c-'0']++;
    }
  }

  printf ("There were %d newlines!\n", nl);
  printf ("There were %d tabs!\n", t);
  printf ("There were %d spaces!\n", s);
  
  for (i=0; i<10; i++) {
    printf ("There were %d %ds!\n", digits[i], i);
  }

  return 0;
}
