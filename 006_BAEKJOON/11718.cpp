#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char temp;
    while(1){
        temp = getchar();
        if(temp == EOF)
            break;
        else
            putchar(temp);
    }
        
    return 0;
}

