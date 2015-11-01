#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>

int main(void){
  int test_case;
  int N, L;
  int cost;
  int day[1005];
  int i, j, k;

  scanf("%d", &test_case);
  for(i=0; i<test_case; i++){
    scanf("%d%d", &N, &L);
    for(j=0; j<N; j++){
      scanf("%d", &cost);
      day[j] = cost;
    }

    for(j=0; j<N; j++){
      printf("%d ", day[j]);
    }
    printf("\n");
  }



  return 0;
}