#include <stdio.h>

unsigned long long result = 28433;

int main(void){
  unsigned long long i;

  for(i=0; i<7830457; i++){
    result = result << 1;
    result = result % 10000000000;
  }

  result += 1;
  result %= 10000000000;

  printf("%llu\n", result);

}