#include <stdio.h>

int main() {
  int myint = 5;
  float myfloat = 8.9;
  char mystring[] = "Hello";

  struct mystruct { 
    int structInt;
    int structArr[5];
  };
  
  struct mystruct a;
  struct mystruct* aPtr;
  aPtr = &a;
  a.structInt = 7;

  int* intPtr = &myint;
  char* stringPtr = mystring;
  
  printf("variable \t\t value \t\t address \t\t size\n");
  printf("myint \t\t\t%d\t\t\t%p\t\t%d\n", myint, &myint, sizeof(myint));
  printf("myfloat \t\t%f\t\t%p\t\t%d\n", myfloat, &myfloat, sizeof(myfloat));
  printf("mystring \t\t%s\t\t\t%p\t\t%d\n", mystring, &mystring, sizeof(mystring));
  printf("a (structure) \t\t%d\t\t%p\t\t\t%d\n", a, &a, sizeof(a));
  printf("intPtr \t\t\t%p\t\t%p\t\t%d\n", intPtr, &intPtr, sizeof(intPtr));
  printf("stringPtr \t\t%p\t\t%p\t\t%d\n", stringPtr, &stringPtr, sizeof(stringPtr));
  printf("aPtr \t\t\t%p\t\t%p\t\t%d\n", aPtr, &aPtr, sizeof(aPtr));
  

  printf("Value of myint: %d\n", *intPtr);
  printf("Value of struct: %d\n", *aPtr);

  return 0;
}
