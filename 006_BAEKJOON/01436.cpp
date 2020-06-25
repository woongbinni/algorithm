#include <stdio.h>

#define TRUE 1
#define FALSE 0

unsigned long long endnumber[10000];

int check_end(unsigned long long num){
  int threesix = 0;
  while(num != 0){
    if(num % 10 == 6){
      threesix += 1;
      if(threesix == 3){
        break;
      }
    }
    else {
      threesix = 0;
    }
    num /= 10;
  }
  return threesix==3?TRUE:FALSE;
}

void calc_endnumber(int order){
  unsigned long long num = 666;
  for(int i=0; i<order; ){
    if(check_end(num) == TRUE){
      endnumber[i] = num;
      i += 1;
    }
    num += 1;
  }
}

int main(){
  int in;

  scanf("%d", &in);
  calc_endnumber(in);

  printf("%lld\n", endnumber[in-1]);

  return 0;
}