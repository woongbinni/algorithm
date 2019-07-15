#include<stdio.h>
#include<string.h>

char prime[1000001];

void calc(){
  memset(prime, 1, sizeof(prime));
  prime[1] = 0;
  for(int i=2; i<=1000000; ++i){
    if(prime[i] == 1){
      for(int j=2*i; j<=1000000; j+=i){
        prime[j] = 0;      
      }
    }
  }
}

int main(){
  calc();
  int min, max;

  scanf("%d%d", &min, &max);

  for(int i=min; i<=max; ++i){
    if(prime[i] == 1){
      printf("%d\n", i);
    }
  }
  return 0;
}