#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _home_info{
  int idx;
  vector<int> node_list;
}home_info;


int T, N, M;
int home_heat[100001];
home_info home_list[100001];

bool home_cmp(home_info a, home_info b){
  if(a.node_list.size() != b.node_list.size()){
    return a.node_list.size() > b.node_list.size();
  }
  else{
    return home_heat[a.idx] > home_heat[b.idx];
  }
}

void print_home_infos(home_info *list){
  for(int i=1; i<=N; ++i){
    printf("##%d %d %lu\n", list[i].idx, home_heat[list[i].idx], list[i].node_list.size());
  }
}

int main(void){
  int result;
  scanf("%d", &T);

  for(int tc=1; tc<=T; ++tc){
    scanf("%d%d", &N, &M);

    int result = 0;
    int total_heat = 0;

    for(int i=1; i<=N; ++i){
      home_list[i].node_list.clear();
    }

    for(int i=1; i<=N; ++i){
      home_list[i].idx = i;
      scanf("%d", &(home_heat[i]));
      total_heat += home_heat[i];
    }

    for(int i=1; i<=M; ++i){
      int t1, t2;
      scanf("%d%d", &t1, &t2);
      home_list[t1].node_list.push_back(t2);
      home_list[t2].node_list.push_back(t1);
    }

    sort(home_list+1, home_list+(N+1), home_cmp);

//    print_home_infos(home_list);

    int idx = 1;
    while(total_heat > 0){
      int temp = home_heat[home_list[idx].idx];
      if(temp > 0){
        home_heat[home_list[idx].idx] = 0;
        total_heat -= temp;
        result += temp;
      }

      for(int i=0; i<home_list[idx].node_list.size(); ++i){
        if(home_heat[home_list[idx].node_list[i]] >= 0){
          if(home_heat[home_list[idx].node_list[i]] >= temp){
            home_heat[home_list[idx].node_list[i]] -= temp;
            total_heat -= temp;
          }
          else{
            total_heat -= home_heat[home_list[idx].node_list[i]];
            home_heat[home_list[idx].node_list[i]] = 0;
          }
        }
      }
      ++idx;
    }

    printf("#%d %d\n", tc, result);
  }
  return 0;
}

