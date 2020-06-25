#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char button[10];
int target;
int current=100;
int result;

int main(){
  int M;
  memset(button, 0x01, sizeof(button));
  scanf("%d", &target);
  scanf("%d", &M);

  for(int i=0; i<M; ++i){
    int temp;
    scanf("%d", &temp);
    button[temp] = 0;
  }

  result = abs(target - current);

  for(int i=0; i<result; ++i){
    int plus = target + i;
    int plus_btn_cnt = 0;
    if(plus == 0){
      if(button[0] == 1){
        plus_btn_cnt = 1;
      }
      else{
        continue;
      }
    }
    while(plus != 0){
      if(button[plus % 10] == 1){
        plus_btn_cnt++;
        plus /= 10;
      }
      else{
        break;
      }  
    }
    if(plus == 0){
      if(plus_btn_cnt + i < result){
        result = plus_btn_cnt + i;
        break;
      }      
    }
  }

  for(int i=0; i<result; ++i){
    int minus = target - i;
    int minus_btn_cnt = 0;
    if(minus == 0){
      if(button[0] == 1){
        minus_btn_cnt = 1;
      }
      else{
        continue;
      }
      if(minus_btn_cnt + i < result){
        result = minus_btn_cnt + i;
        break;
      }      
    }
    else if(minus > 0){
      while(minus != 0){
        if(button[minus % 10] == 1){
          minus_btn_cnt++;
          minus /= 10;
        }
        else{
          break;
        }  
      }
      if(minus == 0){
        if(minus_btn_cnt + i < result){
          result = minus_btn_cnt + i;
        break;
        }      
      }
    }
    else {
      continue;
    }
  }

  printf("%d\n", result);

  return 0;
}