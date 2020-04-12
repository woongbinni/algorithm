#include <stdio.h>

#define MIN(A,B) A>B?B:A

 int main(){
     int bugger_a, bugger_b, bugger_c;
     int drink_a, drink_b;
     int min_bugger;
     int min_drink;

     scanf("%d%d%d", &bugger_a, &bugger_b, &bugger_c);
     scanf("%d%d", &drink_a, &drink_b);

     min_bugger = MIN(MIN(bugger_a, bugger_b), bugger_c);
     min_drink = MIN(drink_a, drink_b);
     
     printf("%d\n", min_drink+min_bugger-50);

     return 0;
 }