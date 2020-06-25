#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char num[1001];

int main(void){
  for(int i=1; i<=1000; ++i){
    if(i < 100){
      num[i] = 1; 
    }
    else if(i == 1000){
      num[i] = 0;
    }
    else{
      int temp01=i/100;
      int temp02=(i%100)/10;
      int temp03=i%10;

      if(temp01-temp02 == temp02-temp03){
        num[i] = 1;
      }
      else{
        num[i] = 0;
      }
    }
  }

  int in;
  int result = 0;
  scanf("%d", &in);

  for(int i=1; i<=in; ++i){
    if(num[i] == 1)
      result += 1;
  }
  printf("%d\n", result);

  return 0;
}
