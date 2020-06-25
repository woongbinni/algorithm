#include <stdio.h>

char board[50][50];
char compare[2][10] = {"WBWBWBWB", "BWBWBWBW"};

int scan_board(int x, int y){
  int diff1 = 0;
  int diff2 = 0;
  for(int i=0; i<8; ++i){
    for(int j=0; j<8; ++j){
      if(board[x+i][y+j] != compare[i%2][j]){
        diff1 += 1;
      }
      if(board[x+i][y+j] != compare[(i+1)%2][j]){
        diff2 += 1;
      }
    }
  }
  return diff1<diff2?diff1:diff2;
}

int main(){
  int N, M;
  int ret = 64;
  scanf("%d%d", &N, &M);

  for(int i=0; i<N; ++i){
    char str[51];
    scanf("%s", str);
    for(int j=0; j<M; ++j){
      board[i][j] = str[j];
    }
  }
  
  for(int i=0; i<=N-8; ++i){
    for(int j=0; j<=M-8; ++j){
      int var = scan_board(i, j);
      if(var < ret){
        ret = var;
      }
    }
  }
  printf("%d\n", ret);

  return 0;
}