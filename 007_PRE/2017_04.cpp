/*
1. 향초 입력 받기

 2. 입력 받은 향초를 유효기간 + 지속시간 으로 정렬하기

    (왜냐하면 유효기간 + 지속기간 가장 긴게 제일 뒤에 오는게 가장 오래 할 수 있기 때문)

 3. 정렬된 배열을 향초 갯수 만큼 돌면서 

    3.1 향초를 꺼낸다.

    3.2 꺼낸 향초를 가지고 최대 지속가능한 길이 배열에 만들어간다.        (배열 길이는 가능한 최대 길이 지속시간 * 향초개수)

        - 예를 들어 (0,4) (4,4), (3,9) 순서이면

        - 처음에 1번 (0,4)를 배열에 넣는다. 그리고 두번째인 (4,4)를 넣는데 앞에 있는것에 더해 배열에

          즉 1, 1+2, 2 이런 경우의 수가 발생함으로써 반복적으로 하면 모든 경우의 수가 나옴)

 

        - 이때 주의 해야 할 것은 앞에 있는것과 더할 때 유효기간 체크 필수

        - 또 다른 주의 사항은 앞에 있는숫자들이 늘어나면 늘어날수록 해야 하는 연산이 많아지기 때문에 

         이미 최대 지속가능한 길이 배열에 들어간 숫자는 넣지 않는다. (넣은 숫자 체크 필요)

           

4. 그러면 최대 지속가능길이 배열에 모든 경우의 수가 들어가고 이 배열 최대값이 답이 된다.

*/

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
