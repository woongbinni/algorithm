#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  int test_case;
  int N, L;
  int cost;
  int day[1005];
  int i, j, k, l;
  double sum;
  double temp;
  double result;

  scanf("%d", &test_case);
  for(i=0; i<test_case; i++){
    result = 99999;
    sum = 0;
    memset(day, 0x00, sizeof(day));
    scanf("%d%d", &N, &L);

    for(j=0; j<N; j++){
      scanf("%d", &cost);
      day[j] = cost;
    }

    for(j=L; j<=N; j++){
      for(k=0; k<=N-j; k++){
        sum = 0;
        for(l=k; l<k+j; l++){
          sum += day[l];
        }
        temp = (double)sum/j;
        if(temp < result){
          result = temp;
        }
      }
    }

    printf("%.11f\n", result);
  }

  return 0;
}