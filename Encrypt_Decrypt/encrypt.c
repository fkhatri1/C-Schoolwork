/*Faysal Khatri*/
/*06-13-2017*/


#include <stdio.h>
#include <string.h>
void encrypt();

char s[];
char key[] = "AZ";
int i;
int validInput = 0;  

int main() {
  int sLen;

  scanf("%[^\n]s", s);
  validInput = 1;
  sLen = strlen(s);
 
  /*Convert to Upper Case*/
  for (i=0; i<sLen; i++) {
    s[i] = toupper(s[i]);
  }    
  /*Only A-Z and spaces will be allowed*/
  for (i=0; i<strlen(s); i++) {
    if (!( (s[i] == ' ') || (s[i] >= 'A' && s[i] <='Z')) ) {
      validInput = 0;       
      break;
    }
  }
  
  if (validInput) {
   encrypt();
  }
  else {
   printf("Invalid input detected. Only A-Z and spaces allowed.\n");
  }
  return 0;
}

void encrypt() {
  
  int keyLen = strlen(key);
  int sLen = strlen(s);
  unsigned char encrypted[sLen];
  
  /* encrypt using seed key */ 
  for (i=0; i<keyLen; i++) {
    encrypted[i] = (s[i] + key[i]);
  }
  
  /* encrypt using encrypted chars */
  for (i=keyLen; i<sLen; i++) {
    encrypted[i] = (s[i] + s[i - keyLen]);
  }

  printf("%s", encrypted);
}

