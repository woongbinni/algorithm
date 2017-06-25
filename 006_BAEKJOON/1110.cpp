#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void){
  int in;
  int first_a, first_b;
  int temp_a, temp_b;
  int result = 0;
  scanf("%d", &in);

  first_a = in / 10;
  first_b = in % 10;

  temp_a = first_b;
  temp_b = first_a + first_b;
  result += 1;

  while(1){
    //printf("%d | %d %d %d %d \n", result, first_a, first_b, temp_a, temp_b);
    //sleep(1);
    if(temp_a == first_a && temp_b == first_b){
      break;
    }
    else{
      int temp = temp_b;
      temp_b = (temp_a + temp_b) %10;
      temp_a = temp;
      result += 1;
    }
  }

  printf("%d\n", result);

  return 0;
}
