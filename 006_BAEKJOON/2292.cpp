#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[20001];

int main(void){
  arr[0] = 1;
  for(int i=1; i<=20000; ++i){
    arr[i] = arr[i-1] + (6 * (i-1));
    printf("%d\n", arr[i]);
    if(arr[i] > 1000000000){
      printf("%d\n", i);
      break;
    }
  }

  return 0;
}
