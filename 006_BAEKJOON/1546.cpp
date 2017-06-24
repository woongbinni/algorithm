#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
float real[1001];

int main(void){
  int max = 0;
  float result = 0;

  scanf("%d", &N);

  for(int i=1; i<=N; ++i){
    scanf("%f", &(real[i]));
    if(real[i] > max){
      max = real[i];
    }
  }
  for(int i=1; i<=N; ++i){
    result += ((real[i]/max) * 100);
  }
  printf("%.2f\n", result/N);

  return 0;
}

