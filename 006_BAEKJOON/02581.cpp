#include<stdio.h>
#include<string.h>

char prime[10001];

void calc(){
  memset(prime, 1, sizeof(prime));
  prime[1] = 0;
  for(int i=2; i<=10000; ++i){
    if(prime[i] == 1){
      for(int j=2*i; j<=10000; j+=i){
        prime[j] = 0;      
      }
    }
  }
}

int main(){
  calc();
  int min, max;
  unsigned int sum = 0;
  int min_prime;

  scanf("%d%d", &min, &max);
  min_prime = max;


  for(int i=min; i<=max; ++i){
    if(prime[i] == 1){
      sum += i;
      if(i < min_prime){
        min_prime = i;
      }
    }
  }
  
  if(sum == 0){
    printf("-1\n");
  }
  else{
    printf("%d\n%d\n", sum, min_prime);
  }

  return 0;
}