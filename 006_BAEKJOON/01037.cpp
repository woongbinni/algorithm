#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int num;
  int input[50];
  scanf("%d", &num);
  for(int i = 0; i < num; i++) {
    scanf("%d", &input[i]);    
  }
  //sort input ascending order by library
  qsort(input, num, sizeof(int), [](const void* a, const void* b) -> int {
    return *(int*)a - *(int*)b;
  });

  if(num %2 == 0) {
    printf("%d\n", input[0] * input[num-1]);
  } else {
    printf("%d\n", input[num/2] * input[num/2]);
  }
  return 0;
}