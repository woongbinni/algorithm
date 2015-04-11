#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int test_case = 0;

  scanf("%d", &test_case);

  for(int i=0; i<test_case; i++){
    int shiness;
    int output = 0;
    int clap_people = 0;
    scanf("%d", &shiness);
    char audience[shiness+1];
    memset(audience, '\0', sizeof(audience));
    scanf("%s", audience);
    for(int j=0; j<=shiness; j++){
      clap_people += (audience[j]-'0');
      if(clap_people < j+1){
        output += (j+1-clap_people);
        clap_people = j+1;
      }
    }
    printf("Case #%d: %d\n", i+1, output);
  }

  return 0;
}