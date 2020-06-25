#include <stdio.h>

int main(void){
        int input;
        int i, j;

        scanf("%d", &input);

        for(i=1; i<=input; ++i){
                for(j=0; j<input-i; ++j){
                        printf(" ");
                }
                for(j=0; j<i; ++j){
                        printf("*");
                }
                printf("\n");
        }

        return 0;
}
