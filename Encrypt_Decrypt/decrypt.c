/*Faysal Khatri*/
/*06-13-2017*/


#include <stdio.h>
#include <string.h>
void decrypt();

unsigned char s[];
char key[] = "AZ";
int i;
int validInput = 0;  

int main() {
  
  scanf("%[^\n]s", s);
  validInput = 1;
 
  for (i=0; i<strlen(s); i++) {
    if ( (s[i] < 64) || (s[i] > 180) ) { /* encrypted value range is 97 to 180 */
      validInput = 0;
    }
  }
  
  if (validInput) {
    decrypt();
  }
  else {
    printf ("Input cannot be decrypted.\n");
  }

  return 0;
}


void decrypt() {
  
  int keyLen = strlen(key);
  int sLen = strlen(s);
  char decrypted[sLen];
 
  /* decrypt using seed key */ 
  for (i=0; i<keyLen; i++) {
    decrypted[i] = (s[i] - key[i]);
  }
 
  /* decrypt using decrypted chars */
  for (i=keyLen; i<sLen; i++) {
    decrypted[i] = (s[i] - decrypted[i - keyLen]);
  }

 printf("%s\n", decrypted);
}
