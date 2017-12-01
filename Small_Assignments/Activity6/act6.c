#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int main() {
  typedef struct act6_t {
    int myInt;
    char myString[SIZE];
  } act6_t;

  act6_t *sPtr = malloc(sizeof(act6_t));

  printf("Enter a string: \n");
  fgets(sPtr->myString, SIZE, stdin);
  printf("Enter an int: \n");
  scanf("%d", &sPtr->myInt); 

  printf("Structure int value: %d\n", sPtr->myInt);
  printf("Structure string value: %s\n", sPtr->myString);

  return 0;
}
