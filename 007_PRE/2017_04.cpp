#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

int T, N;
vector<int> oil[1000001];
int smell[1000001];

int main(void)
{
  scanf("%d", &T);

  for(int tc=1; tc<=T; ++tc){
    int result = 0;
    scanf("%d", &N);


    memset(smell, 0x00, sizeof(smell));

    for(int i=0; i<N; ++i){
      int limit, duration;
      scanf("%d%d", &limit, &duration);
      oil[limit].push_back(duration);
      if(smell[limit] < duration){
        smell[limit] = duration;
      }
    }

    int elapsed = 0;

    for(int i=0; i<1000001; ++i){
      if(oil[i].size() == 0)
        continue;




    }
  }

  return 0;
}
