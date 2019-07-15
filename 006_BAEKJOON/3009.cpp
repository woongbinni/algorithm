#include <stdio.h>
#include <string.h>

int hor[1001];
int ver[1001];

int main(){
  memset(hor, 0, sizeof(hor));
  memset(ver, 0, sizeof(ver));

  for(int i=0; i<3; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    hor[x] += 1;
    ver[y] += 1;
  }
  for(int i=1; i<1000; ++i){
    if(hor[i] == 1){
      printf("%d ", i);
    }
  }
  for(int i=1; i<1000; ++i){
    if(ver[i] == 1){
      printf("%d\n", i);
    }
  }
  return 0;
}