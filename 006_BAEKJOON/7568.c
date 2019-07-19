#include <stdio.h>

typedef struct {
  int weight;
  int height;
} person;

person people[51];
int rank[51];

int main(){
  int N;

  scanf("%d", &N);

  for(int i=0; i<N; ++i){
    person temp;
    scanf("%d%d", &(temp.weight), &(temp.height));
    people[i] = temp;
  }

  for(int i=0; i<N; ++i){
    person me = people[i];
    int bigger = 1;
    for(int j=0; j<N; ++j){
      if(i == j){
        continue;
      }
      if(people[j].weight > me.weight && people[j].height > me.height){
        bigger += 1;
      }
    }
    rank[i] = bigger;
  }

  for(int i=0; i<N; ++i){
    printf("%d ", rank[i]);
  }
  printf("\n");

  return 0;
}