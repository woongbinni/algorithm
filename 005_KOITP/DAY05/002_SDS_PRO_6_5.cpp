/********************************************************************************
## 문제
세계적인 도둑 동현이는 보석점을 털기로 결심했다.

동현이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 동현이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 각 가방에는 최대 한 개의 보석만 넣을 수 있다.

동현이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)
다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (1 ≤ Mi, Vi ≤ 1,000,000)
다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)
모든 숫자는 양의 정수이다.

출력
첫째 줄에 동현이가 훔칠 수 있는 보석 가격의 합의 최대값을 출력한다.

힌트
입력 예제

3 2
1 65
5 23
2 99
10
2
출력 예제

164
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct _jewel{
	int weight;
	int price;
}jewel;

bool cmp(const jewel a, const jewel b){
	return a.weight < b.weight;
}

jewel jewels[300001];
int bag[300001];
priority_queue<int, vector<int>, less<int> > max_heap;
int N, K;

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=1;i<=N;i++){
    	scanf("%d%d", &jewels[i].weight, &jewels[i].price);
    } 
    for (int i=1;i<=K;i++){
    	scanf("%d", &(bag[i]));
    } 
    sort(bag+1, bag+K+1);
    sort(jewels+1, jewels+N+1, cmp);

    long long result = 0;
    for (int i=1,j=1;i<=K;i++){
        while (j <= K && jewels[j].weight <= bag[i]){
        	max_heap.push(jewels[j++].price);       	
        } 
        if (!max_heap.empty()){
        	result += max_heap.top();
        	max_heap.pop();
        }
    }
    printf("%lld\n", result);
}
