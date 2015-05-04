#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define P_MAX 1001

int calc_pancake(int* plate, int min);
void eat_pancake(int *plate);
void serve_pancake(int *plate, int max_idx);

int main(void){
  int test_case;
  int i, k;
  int pancakeNum;
  scanf("%d", &test_case);

  for(i=0; i<test_case; i++){
    int diner = 0;
    scanf("%d", &diner);
/*    memset(plate, 0x00, sizeof(plate));
    for(int k=0; k<11; k++){
      plate[k] = 0;
      printf("plate[%d] : %d", k, plate[k]);
    } */
      int plate[P_MAX];
      memset(plate, 0x00, sizeof(plate));

      for(k=0; k<diner; k++){
        scanf("%d", &pancakeNum);
        int temp = plate[pancakeNum];
        plate[pancakeNum] = temp + 1;
/*
      for(int j=0; j<11; j++){
        printf("%d ", plate[j]);
      }
      printf("\n");
      */
    }
    int minutes = calc_pancake(plate, 0);
    printf("Case #%d: %d\n", i+1, minutes);
  }
  return 0;
}

int calc_pancake(int* plate, int min){
  int max;
  int i;
  
  printf("min %02d : ", min);
 for(i=0; i<P_MAX; i++){
    printf("%d ", plate[i]);
  }
  printf("\n");
  
//  sleep(1);
  for(i=P_MAX-1; i>=1; i--){
    if(plate[i] != 0){
      max = i;
//      printf("MAX : %d\n", max);
      break;
    }
  }
//  printf("MAX : %d , min : %d\n", max, min);
  if(i == 0 || max == 0){
//    printf("return min : %d\n", min);
    return min;
  }
  int eat_plate[P_MAX];
  for(int i=0; i<P_MAX; i++){
    int temp = plate[i];
    eat_plate[i] = temp;
  }
  eat_pancake(eat_plate);
  int eat_case = calc_pancake(eat_plate, min+1);
  if(max < 2){
//    printf("return eat_case : %d\n", eat_case);
    return eat_case;
  }

  int serve_plate[P_MAX];
  for(int i=0; i<P_MAX; i++){
    int temp = plate[i];
    serve_plate[i] = temp;
  }
  serve_pancake(serve_plate, max);
  int serve_case = calc_pancake(serve_plate, min+1);
//  printf("return eat_case : %d vs serve_case : %d\n", eat_case, serve_case);
  return ((eat_case>serve_case) ? serve_case : eat_case);
}


void eat_pancake(int *plate){
  for(int i=1; i<P_MAX; i++){
    int temp = plate[i];
    plate[i-1] = temp;
  }
  return;
}

void serve_pancake(int *plate, int max_idx){
  int temp01 = max_idx - (max_idx/2);
  int temp02 = (max_idx/2);
  int temp03;
  temp03 = plate[max_idx];
  plate[max_idx] = temp03 - 1;
  temp03 = plate[temp01];
  plate[temp01] = temp03 + 1;
  temp03 = plate[temp02];
  plate[temp02] = temp03 + 1;

  return;
}