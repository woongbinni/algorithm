#include <stdio.h>
#include <math.h>

int main(void){
  int tc;
  scanf("%d", &tc);
  for(int i=0; i<tc; ++i){
    int x1, y1, x2, y2, r1, r2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
    if(x1 == x2 && y1 == y2){
      if(r1 == r2){
        printf("-1\n");
      }
      else {
        printf("0\n");
      }
    }
    else{
      int width = abs(x1-x2);
      int height = abs(y1-y2);
      if(width*width + height*height > (r1+r2)*(r1+r2)){
        printf("0\n");
      }
      else if(width*width + height*height == (r1+r2)*(r1+r2)){
        printf("1\n");
      }
      else {
        printf("2\n");
      }
    }
  }
}