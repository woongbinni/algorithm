#include <stdio.h>

int tile[1000001];

int main(){
  tile[1] = 1;
  tile[2] = 2;

  int N;
  scanf("%d", &N);

  for(int i=3; i<=N; ++i){
    tile[i] = (tile[i-1] + tile[i-2])%15746;
  }

  printf("%d\n", tile[N]);

  return 0;
}