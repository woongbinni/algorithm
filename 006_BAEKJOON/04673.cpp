#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[10001];
void solve(int i){
  if(i > 10000)
    return;
  int next = i;
  while(i != 0){
    next += (i%10);
    i /= 10;
  }
  arr[next] = 0;
  solve(next);
}

int main(void){
  memset(arr, 1, sizeof(arr));

  for(int i=1; i<= 10000; ++i){
    if(arr[i] == 1){
      solve(i);
    }
    else
      continue;
  }

  for(int i=1; i<= 10000; ++i){
    if(arr[i] == 1)
      printf("%d\n", i);
  }

  return 0;
}
