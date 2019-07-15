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
  int tc;
  scanf("%d", &tc);

  for(int i=0; i<tc; ++i){
    int in, half;
    scanf("%d", &in);
    half = in/2;
    for(int j=half; j>=2; --j){
      if(prime[j] == 1 && prime[in - j] == 1){
        printf("%d %d\n", j, in-j);
        break;
      }
    }
  }
  
  return 0;
}