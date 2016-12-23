#include <iostream>
using namespace std;
#include <stdio.h>

int main(void){
	int input;
	int output = 0;
	scanf("%d", &input);

	for(int i=1; i<= input; ++i){
		output += i;
	}
	printf("%d\n", output);

	return 0;
}