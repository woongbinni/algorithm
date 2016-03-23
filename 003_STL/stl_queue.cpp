#include <iostream>
using namespace std;
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int index;
  char name[10];
}person;

int main(void){
  queue<person> people;

  printf("01. size of people : %lu\n", people.size());

  for(int i=0; i<10; i++){
    person temp;
    temp.index = i;
    sprintf(temp.name, "Queue%02d", i);
    printf("Push %d : %s\n", temp.index, temp.name);
    people.push(temp);
  }

  printf("02. after push     : %lu\n", people.size());

  while(!people.empty()){
    person temp = people.front();
    printf("Pop %d : %s\n", temp.index, temp.name);
    people.pop();
  }

  printf("03. after pop      : %lu\n", people.size());


  return 0;
}