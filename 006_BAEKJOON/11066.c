#include <stdio.h>
#include <stdlib.h>

int compair(const void *a, const void *b){
  if(*(int*)a > *(int*)b){
    return 1;
  }
  else if(*(int*)a < *(int*)b){
    return -1;
  }
  else{
    return 0;
  }
}


int main(void){
  int T, K;
  unsigned long long dp[501];
  unsigned long long file[501];

  scanf("%d", &T);

  for(int i=0; i<T; ++i){
    scanf("%d", &K);
    for(int j=0; j<K; ++j){
      scanf("%llu", &(file[j]));
    }
    qsort(file, K, sizeof(unsigned long long), compair);

    dp[0] = file[0];
    dp[1] = file[0] + file[1];
    for(int j=2; j<K; ++j){
      dp[j] = dp[j-1] + file[j];
    }
    printf("%llu\n", dp[K-1]);
  }
  return 0;
}