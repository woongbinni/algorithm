/******************************************************************
 *
 * Auther : woongbinni
 *
 * C++ STL stack example
 *
 * ****************************************************************/

#include<iostream>
using namespace std;
#include<stack>
#include<stdio.h>

typedef struct{
	int index;
	char name[10];
}person;

int main(void){
	stack<person> people;

	printf("Before Push : %d\n", people.size());

	int i;

	for(i=0; i<10; i++){
		person temp;
		temp.index = i;
		sprintf(temp.name, "test%02d", i);
		printf("%d : %s\n", temp.index, temp.name);
		people.push(temp);
	}
	
	printf("After Push : %d\n", people.size());

	while(!people.empty()){
		person temp = people.top();
		printf("%d : %s\n", temp.index, temp.name);
		people.pop();
	}
	
	printf("After Pop : %d\n", people.size());

	return 0;
}
