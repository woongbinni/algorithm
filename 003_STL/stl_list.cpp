#include<iostream>
using namespace std;
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int index;
	char name[10];
}person;

class Compare
{
	public :
		bool operator()(const person &a, const person &b) const {
			return a.index < b.index;
		}
};

int main(void){

	list<person> people;
	list<person>::iterator p_people;

	printf("01. people size : %lu\n", people.size());

	for(int i=0; i<10; i++){
		person temp;
		temp.index = i;
		sprintf(temp.name, "list%02d", i);
		people.push_back(temp);
	}

	printf("02. after push_back : %lu\n", people.size());

	for(p_people = people.begin(); p_people != people.end(); p_people++){
		printf("idx : %d, name : %s\n", (*p_people).index, (*p_people).name);
	}

	for(int i=0; i<10; i++){
		person temp;
		temp.index = i;
		sprintf(temp.name, "list%02d", i);
		people.push_front(temp);
	}

	printf("03. after push_front : %lu\n", people.size());

	for(p_people = people.begin(); p_people != people.end(); p_people++){
		printf("idx : %d, name : %s\n", (*p_people).index, (*p_people).name);
	}

	p_people = people.begin();
	for(int i=0; i<10; i++){
		p_people++;
	}
	person temp;
	temp.index = 10;
	sprintf(temp.name, "list10");
	people.insert(p_people, temp);

	printf("04. after insert : %lu\n", people.size());
	
	for(p_people = people.begin(); p_people != people.end(); p_people++){
		printf("idx : %d, name : %s\n", (*p_people).index, (*p_people).name);
	}

	printf("05. sort!!!!\n");
	people.sort(Compare());

	for(p_people = people.begin(); p_people != people.end(); p_people++){
		printf("idx : %d, name : %s\n", (*p_people).index, (*p_people).name);
	}

	return 0;
}



