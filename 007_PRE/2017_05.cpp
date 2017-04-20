#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _home_info{
  vector<int> node_list;
}home_info;

int T, N, M;
long long home_heat[100001];
char visited[100001];
home_info home_list[100001];
list<int> bfs_queue;

void print_home_infos(home_info *list){
  for(int i=1; i<=N; ++i){
    printf("##%d %lld %lu\n", i, home_heat[i], list[i].node_list.size());
  }
}

int main(void){
  int result;
  scanf("%d", &T);

  for(int tc=1; tc<=T; ++tc){
    scanf("%d%d", &N, &M);

    bfs_queue.clear();
    memset(visited, 0x00, sizeof(visited));
    long long result = 0;

    for(int i=1; i<=N; ++i){
      home_list[i].node_list.clear();
    }

    for(int i=1; i<=N; ++i){
      scanf("%lld", &(home_heat[i]));
    }

    for(int i=1; i<=M; ++i){
      int t1, t2;
      scanf("%d%d", &t1, &t2);
      home_list[t1].node_list.push_back(t2);
      home_list[t2].node_list.push_back(t1);
    }

//    print_home_infos(home_list);

    for(int i=1; i<=N; ++i){
      if(home_list[i].node_list.size() == 1){
        bfs_queue.push_back(i);
      }
      else if(home_list[i].node_list.size() == 0){
        result += home_heat[i];
        home_heat[i] = 0;
        visited[i] = 1;
      }
    }

    while(bfs_queue.size() > 0){
      int pop_idx = bfs_queue.front();
      int parent_idx;
      bfs_queue.pop_front();

      long long pop_temp = home_heat[pop_idx];

  //    printf("pop : %d %d\n", pop_idx, pop_temp);

      result += home_heat[pop_idx];
      home_heat[pop_idx] = 0;
      visited[pop_idx] = 1;

      for(int i=0; i<home_list[pop_idx].node_list.size(); ++i){
        if(visited[home_list[pop_idx].node_list[i]] == 0){
          parent_idx = home_list[pop_idx].node_list[i];
          break;
        }
      }
      home_heat[parent_idx] -= pop_temp;
      if(home_heat[parent_idx] < 0){
        home_heat[parent_idx] = 0;
      }

      int node_cnt = 0;
      for(int i=0; i<home_list[parent_idx].node_list.size(); ++i){
        if(visited[home_list[parent_idx].node_list[i]] == 0){
          node_cnt += 1;
          home_heat[home_list[parent_idx].node_list[i]] -= pop_temp;
          if(home_heat[home_list[parent_idx].node_list[i]] < 0)
            home_heat[home_list[parent_idx].node_list[i]] = 0;
        }
      }

      if(node_cnt == 1){
        bfs_queue.push_back(parent_idx);
    //    printf("push: %d\n", home_list[pop_idx].node_list[0]);
      }
    }

    printf("#%d %lld\n", tc, result);
  }
  return 0;
}

