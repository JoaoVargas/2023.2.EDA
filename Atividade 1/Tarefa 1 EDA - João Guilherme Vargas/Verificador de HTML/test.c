#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  char palavra[50];

  for (int i = 1; i < argc; i++) {

    
    // strcpy(palavra "./");
    // strcat(palavra, argv[i]);
    // strcat(palavra, ".txt");
    
    strcpy(palavra, argv[i]);
    // argv[i][strlen(argv[i]) - 5] = '\000';
    // strcpy(palavra, argv[i]);
    
    // strrev(argv[i]);
    // strcpy(palavra, argv[i]);

    // printf("%s", palavra);

    // FILE* fSaida = fopen(palavra, "w");

    // fclose(fSaida);

    int len = strlen(palavra);
    printf("%d \n", len);

    for (int i = 0; i < 4; i++) {
      palavra[len - i] = '\000';
    }
    len = strlen(palavra);

    printf("%d \n", len);
  }
  
  
  
  return 0;
}

void strrev(char* str) {
  // if the string is empty
  if (!str) {
    return;
  }
  // pointer to start and end at the string
  int i = 0;
  int j = strlen(str) - 1;

  // reversing string
  while (i < j) {
    char c = str[i];
    str[i] = str[j];
    str[j] = c;
    i++;
    j--;
  }
}
