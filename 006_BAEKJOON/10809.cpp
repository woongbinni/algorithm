#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[101];
int alphabet[26];

int main(void){
  memset(alphabet, -1, sizeof(alphabet));

  scanf("%s", input);

  for(unsigned int i=0; i<strlen(input); ++i){
    if(alphabet[input[i]-'a'] == -1){
      alphabet[input[i]-'a'] = i;
    }
  }

  for(int i=0; i<26; ++i){
    printf("%d ", alphabet[i]);
  }
  printf("\n");

  return 0;
}
