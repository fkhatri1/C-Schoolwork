#include<stdio.h>
#include<string.h>

int main () {
 int n=0, len;
 char str[ ] = "This is a string.";
 len = strlen(str);
 char* strPtr;
 strPtr = &str;

 for( n=0; n<len; n++)
 putc( *(strPtr+n), stdout);
 printf("\nn = %d\n", n);
}
