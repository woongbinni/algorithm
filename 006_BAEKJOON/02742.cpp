#include <stdio.h>

int main(void){
        int input;
        int i;

        scanf("%d", &input);
        for(i=input; i>0; --i){
                printf("%d\n", i);
        }

        return 0;
}
