#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc_pancake(int* plate, int min);
void eat_pancake(int *plate);
void serve_pancake(int *plate, int max_idx);
int P_MAX = 1001;

int main(void){
  int test_case;
  scanf("%d", &test_case);

  for(int i=0; i<test_case; i++){
    int diner = 0;
    scanf("%d", &diner);
    int plate[P_MAX];
    memset(plate, 0x00, sizeof(plate));
    for(int j=0; j<diner; j++){
      int pan_no;
      scanf("%d", &pan_no);
      printf("%d", pan_no);
      plate[pan_no]+=1;
    }

    int minutes = calc_pancake(plate, 0);
    printf("Case #%d: %d\n", i+1, minutes);
  }
  return 0;
}

int calc_pancake(int* plate, int min){
  int max;
  for(int i=P_MAX-1; i>=1; i--){
    if(plate[i] != 0){
      max = i;
      break;
    }
  }
//  printf("MAX : %d , min : %d\n", max, min);
  if(max == 0){
    return min;
  }
  int eat_plate[P_MAX];
  for(int i=0; i<P_MAX; i++){
    eat_plate[i] = plate[i];
  }
  eat_pancake(eat_plate);
  int eat_case = calc_pancake(eat_plate, min+1);
  if(max < 2){
    return eat_case;
  }

  int serve_plate[P_MAX];
  for(int i=0; i<P_MAX; i++){
    serve_plate[i] = plate[i];
  }
  serve_pancake(serve_plate, max);
  int serve_case = calc_pancake(serve_plate, min+1);
  return ((eat_case>serve_case) ? serve_case : eat_case);
}


void eat_pancake(int *plate){
  for(int i=1; i<P_MAX; i++){
    plate[i] = plate[i+1];
  }
  return;
}

void serve_pancake(int *plate, int max_idx){
  int temp01 = max_idx - (max_idx/2);
  int temp02 = (max_idx/2);

  plate[max_idx] -= 1;
  plate[temp01] += 1;
  plate[temp02] += 1;

  return;
}