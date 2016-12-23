#include<iostream>
using namespace std;
#include <stdio.h>

int main(void){
	int point;
	scanf("%d", &point);

	if(point >= 90 && point <= 100){
		printf("A\n");
	}
	else if(point >= 80 && point < 90){
		printf("B\n");
	}
	else if(point >= 70 && point < 80){
		printf("C\n");
	}
	else if(point >= 60 && point < 70){
		printf("D\n");
	}
	else {
		printf("F\n");
	}

	return 0;
}