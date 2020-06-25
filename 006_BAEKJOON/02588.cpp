#include <iostream>
using namespace std;
#include <stdio.h>

int main(void){
    int a;
    char b1, b2, b3;
    int c1, c2, c3;
    scanf("%d\n", &a);
    scanf("%c%c%c", &b3, &b2, &b1);

    c1 = a*(int)(b1-'0');
    printf("%d\n", c1);

    c2 = a*(int)(b2-'0');
    printf("%d\n", c2);
    c2 *= 10;

    c3 = a*(int)(b3-'0');
    printf("%d\n", c3);
    c3 *= 100;

    printf("%d\n", c1 + c2 + c3);

    return 0;
}