#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int T, N;
float mark[1001];

int main(void){
  scanf("%d", &T);

  for(int tc=0; tc<T; ++tc){
    scanf("%d", &N);
    float avg = 0;

    for(int i=0; i<N; ++i){
      scanf("%f", &(mark[i]));
      avg += mark[i];
    }
    avg /= N;
    int avg_over = 0;

    for(int i=0; i<N; ++i){
      if(mark[i] > avg)
        avg_over += 1;
    }

    printf("%.3f%%\n", (((float)avg_over/N) * 100));
  }

  return 0;
}

