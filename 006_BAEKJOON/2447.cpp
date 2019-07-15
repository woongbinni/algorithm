#include <stdio.h>
#include <string.h>

char map[2188][2188];

void draw(int length, int x, int y){
  int div_length = length/3;
  for(int i=x+div_length; i<x+(div_length*2); ++i){
    for(int j=y+div_length; j<y+(div_length*2); ++j){
      map[i][j] = ' ';
    }
  }
  if(div_length > 1){
    draw(div_length, x, y);
    draw(div_length, x, y+div_length);
    draw(div_length, x, y+2*div_length);
    draw(div_length, x+div_length, y);
    draw(div_length, x+div_length, y+2*div_length);
    draw(div_length, x+2*div_length, y);
    draw(div_length, x+2*div_length, y+div_length);
    draw(div_length, x+2*div_length, y+2*div_length);
  }
}

int main(){
  int in;
  memset(map, '*', sizeof(map));

  scanf("%d", &in);

  draw(in, 0, 0);

  for(int i=0; i<in; ++i){
    for(int j=0; j<in; ++j){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }

  return 0;
}