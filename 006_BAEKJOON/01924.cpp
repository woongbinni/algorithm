#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char day[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void){
  int mon, date;
  int total_date = 0;
  scanf("%d %d", &mon, &date);

  for(int i=0; i<mon; ++i){
    total_date += month[i];
  }
  total_date += date;
  total_date %= 7;

  printf("%s\n", day[total_date]);

  return 0;
}
