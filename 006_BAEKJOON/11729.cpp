#include <stdio.h>

int count = 0;
typedef struct{
  char from;
  char to;
} move;

move moves[1048576];

void hanoi(int n, char from, char temp, char to){
  if(n == 1){
    moves[count].from = from;
    moves[count].to = to;
    count += 1;
  }
  else{
    hanoi(n-1, from, to, temp);
    moves[count].from = from;
    moves[count].to = to;
    count += 1;
    hanoi(n-1, temp, from, to);
  }
}
int main(){
  int in;
  scanf("%d", &in);
  hanoi(in, '1', '2', '3');
  printf("%d\n", count);
  for(int i=0; i<count; ++i){
    printf("%c %c\n", moves[i].from, moves[i].to);
  }

  return 0;
}