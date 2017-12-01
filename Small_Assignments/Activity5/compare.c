#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100


/*
 *chomp makes sure there is a null terminator at the end of each line
 */

void chomp(char * ptr) {
  while(*ptr != '\n') {
    ptr++;
  }
  *ptr='\0';
}



int main(int argc, char *argv[]) {
  FILE *infile1, *infile2;
  char buffer1[SIZE];
  char buffer2[SIZE];
  int i = 1;

  infile1 = fopen(argv[1], "r");
  infile2 = fopen(argv[2], "r");

 
  int f1 = fgets(buffer1, SIZE, infile1);
  int f2 = fgets(buffer2, SIZE, infile2);
  
  while ( f1 || f2 ) {
     chomp(buffer1);
     chomp(buffer2); 
     if (strncmp(buffer1, buffer2, SIZE) != 0) {
       printf("Difference found at line number %d:\n", i);
       printf("\tText of file '%s':\n\t\t%s\n", argv[1], buffer1);
       printf("\tText of file '%s':\n\t\t%s\n", argv[2], buffer2);
       break;
     }
     f1 = fgets(buffer1, SIZE, infile1);
     f2 = fgets(buffer2, SIZE, infile2);
 
     i++;
  }

  fclose(infile1);
  fclose(infile2);

  return 0;
}
