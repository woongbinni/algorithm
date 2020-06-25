#include <stdio.h>
#include <unistd.h>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[502][502];
int dp[502][502];
int Y, X;

void print_map(){
  sleep(1);
  for(int i=1; i<=Y; ++i){
    for(int j=1; j<=X; ++j){
      printf("%d\t", dp[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int calc(int y, int x){
  if(y == 1 && x == 1){
    return 1;
  }

  if(dp[y][x] == -1){
    dp[y][x] = 0;
    for(int i=0; i<4; ++i){
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if(nx >= 1 && nx<=X && ny >=1 && ny <=Y){
        if(map[y][x] < map[ny][nx]){
          dp[y][x] += calc(ny, nx);
        }
      }
    }
  }
  // print_map();
  return dp[y][x];
}

int main(void){
  scanf("%d%d", &Y, &X);
  for(int i=1; i<=Y; ++i){
    for(int j=1; j<=X; ++j){
      scanf("%d", &(map[i][j]));
      dp[i][j] = -1;
    }
  }

  printf("%d\n", calc(Y, X));
  return 0;
}