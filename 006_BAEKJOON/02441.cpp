int main(void){
        int input;
        int i, j;

        scanf("%d", &input);

        for(i=input; i>=1; --i){
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
