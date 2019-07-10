#include <stdio.h>

int main(){
    int hh, mm;
    int HH, MM;
    scanf("%d%d", &hh, &mm);

    HH = hh;
    MM = mm - 45;
    if(MM < 0){
        MM += 60;
        HH -= 1;
    }

    if(HH < 0){
        HH = 23;
    }

    printf("%d %d\n", HH, MM);

    return 0;
}