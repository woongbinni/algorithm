#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
char str[101];

int main(void){
  int result = 0;

  scanf("%d", &N);
  scanf("%s", str);

  for(int i=0; i<N; ++i){
    result += (str[i]-'0');
  }

  printf("%d\n", result);

  return 0;
}
