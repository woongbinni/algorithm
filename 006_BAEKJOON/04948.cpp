#include<stdio.h>
#include<string.h>

char prime[250001];

void calc(){
  memset(prime, 1, sizeof(prime));
  prime[1] = 0;
  for(int i=2; i<=250000; ++i){
    if(prime[i] == 1){
      for(int j=2*i; j<=250000; j+=i){
        prime[j] = 0;      
      }
    }
  }
}

int main(){
  calc();
  int in;

  do{
    scanf("%d", &in);
    int ret = 0;
    for(int i=in+1; i<=2*in; ++i){
      if(prime[i] == 1){
        ret += 1;
      }
    }
    if(in != 0){
      printf("%d\n", ret);
    }
  }while(in != 0);

  return 0;
}