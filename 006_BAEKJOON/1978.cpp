#include<stdio.h>
#include<string.h>

char prime[1001];

void calc(){
  memset(prime, 1, sizeof(prime));
  prime[1] = 0;
  for(int i=2; i<=1000; ++i){
    if(prime[i] == 1){
      for(int j=2*i; j<=1000; j+=i){
        prime[j] = 0;      
      }
    }
  }
}

int main(){
  calc();

  for(int i=1; i<=1000; ++i){
    if(prime[i] == 1){
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}