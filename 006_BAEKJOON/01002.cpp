#include <stdio.h>
#include <math.h>

int main(){
  int tc;
  scanf("%d", &tc);
  for(int i=0; i<tc; ++i){
    int x1, y1, x2, y2, r1, r2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
    int width = abs(x1-x2);
    int height = abs(y1-y2);
    float distance = (float)sqrt(width*width + height*height);
    if(r1 > r2){
      int temp = r1;
      r1 = r2;
      r2 = temp;
    }

    if(x1 == x2 && y1 == y2 && r1 == r2){
      printf("-1\n");
    }
    else if(distance + r1 < r2 || distance > r1 + r2){
      printf("0\n");
    }
    else if(distance + r1 == r2 || distance == r1 + r2){
      printf("1\n");
    }
    else {
      printf("2\n");
    }
  }
  return 0;
}