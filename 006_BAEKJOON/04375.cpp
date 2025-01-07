#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int n;
  while (scanf("%d", &n) != EOF)
  {
      unsigned long long dividened = 1;
      int one_count = 1;
      while (dividened % n != 0)
      {
        dividened = (dividened * 10 + 1) % n;
        one_count += 1;
      }
      printf("%d\n", one_count);
  }

  return 0;
}