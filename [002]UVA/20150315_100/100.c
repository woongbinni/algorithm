/*******************************************************************************
100 - The 3n + 1 problem
@Auther : Song Woong-bin
@Since  : 2015/03/15
@Result : Accepted 
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned int result[1000000];

int main(void){
	unsigned int i, j, k;
	unsigned int input01, input02, output;
	unsigned int temp01, temp02, temp;

	memset(result, 0, sizeof(result));

	for(i=1; i<1000000; i++){
		j = i;
		k = 0;
		while(j!=1){
			if(j%2 == 1){
				j = (3*j) + 1;
			}
			else {
				j = j/2;
			}
			k += 1;
		}
		k += 1;
		result[i] = k;
	}

	while(scanf("%d %d", &input01, &input02) != EOF){
		temp01 = input01;
		temp02 = input02;

		if(temp01 > temp02){
			temp = temp01;
			temp01 = temp02;
			temp02 = temp;
		}

		output = 0;
		for(i=temp01; i<=temp02; i++){
			if(output < result[i]){
				output = result[i];
			}
		}

		printf("%d %d %d\n", input01, input02, output);
	}
	return 0;
}

