/*
[문제]
지역난방공사에서 근무하는 유프로는 자신이 관리하는 지역의 각 가구마다 희망하는 온도에 맞춰 난방을 실시하고 있다. 가구마다 희망하는 온도가 다르며, 1℃ 의 온도를 올리기 위해서는 1시간의 난방이 필요하다. 또한, 한 가구에 난방을 가동하여 온도를 올리면 그 가구와 배관으로 연결된 인접한 가구도 온도가 올라간다. 예를 들어 1번-2번, 1번-3번 가구가 배관으로 연결되어 있고, 1, 2, 3번 가구가 희망온도에서 각각 3, 8, 5 ℃가 부족할 때 1번 가구에 3시간 난방을 가동하면 1, 2, 3번 가구 모두 3℃ 상승하게 된다. 반면, 2번 가구에 3시간 난방을 가동하면 1, 2번 가구는 3℃ 상승하고 3번 가구는 난방이 되지 않는다.
국가적인 에너지 절약 차원에서 유프로는 모든 가구의 희망온도를 만족시키는 최소 시간을 구하고자 한다. 유프로가 관리하는 지역의 가구 수(N), 각 가구의 희망온도에서 부족한 온도(W1, W2, …, Wn), 가구가 서로 연결되어 있는 배관의 수(M), 배관에 연결된 두 가구의 번호가 주어질 때, 모든 가구의 희망온도를 만족시키는 최소 시간을 구하는 프로그램을 작성하라.

[제한조건]
1. 임의의 두 가구 사이에는 정확히 한 가지 경로만 존재한다.
2. 한 가구에 난방을 가동하여 온도를 올리면 그 가구와 직접 배관으로 연결된 인접한 가구의 온도만 올라간다.
3. 가구의 희망온도를 초과하여 난방되어도 무방하며, 올라간 온도는 다시 떨어지지 않는다.
4. 지역난방공사는 한 번에 한 가구에만 난방을 가동할 수 있다.

[입력]
최초 테스트케이스의 개수 T가 주어지며, 다음 줄부터 T개의 테스트 케이스가 주어진다. 각 테스트 케이스마다 첫번째 줄에는 지역의 가구수 N(2≤N≤100,000), 가구끼리 연결된 배관의 수 M(1≤M≤100,000)이 공백을 두고 주어지며, 다음 줄에 각 가구의 희망온도에서 부족한 온도 Wi가 (1≤Wi≤1,000,000)가 공백을 두고 순서대로 N개 주어진다. 그 다음 M개의 줄에는 각 배관마다 서로 연결된 두 가구의 정보가 공백으로 구분되어 주어진다.

[출력]
각각의 테스트 케이스에 대하여 #x (x는 테스트 케이스 번호, 1부터 시작)을 출력하고 공백을 하나 둔 다음, 모든 가구의 희망온도를 만족시키는 최소 난방 시간을 시간단위로 출력한다.

[입출력예제]
입력
5
4 3
12 11 14 17 
3 4
3 1
3 2
4 3
6 13 19 10 
1 4
1 2
4 3
6 5
7 7 10 6 6 3 
5 1
3 6
3 5
6 4
6 2
8 7
12 10 16 2 9 9 16 17 
1 8
3 5
4 2
8 6
6 3
3 7
8 4
7 6
4 7 1 7 19 17 4 
6 2
1 7
1 5
4 1
4 6
7 3

출력
#1 17
#2 32
#3 14
#4 38
#5 37

*/

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

