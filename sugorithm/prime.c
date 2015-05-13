#include <stdio.h>
#include <stdlib.h>

int main(void){

	int test, div_cnt, one_cnt, zero_cnt, firstOne;



	while(scanf("%d", &test) != EOF){

		div_cnt = one_cnt = zero_cnt = firstOne = 0;

		while(test != 0){
			if(test % 2 == 1){
				one_cnt += 1;
				if(firstOne == 0)
					firstOne = 1;
			}
			else {
				zero_cnt += 1;
				if(firstOne == 1){
					div_cnt += 1;
					test /= 2;
					break;
				}
			}
			div_cnt += 1;
			test /= 2;
		}

		if(test == 0){
			div_cnt += 1;
			zero_cnt += 1;
		}

		test *= 2;
		test += 1;
		one_cnt -= 1;
		div_cnt -= 1;
		if(div_cnt == 0){
			test *= 2;
		}
		else {
			while(div_cnt > 0){
				test *= 2;
				if(zero_cnt > 0){
					zero_cnt -= 1;
				} 
				else if(one_cnt > 0){
					test += 1;
					one_cnt -= 1;
				}
				div_cnt -= 1;
			}
		}

		printf("result : %d\n", test);

	}

	return 0;
}
