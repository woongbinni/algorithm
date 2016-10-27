/*
## 문제
 
소들은 롤러코스터를 짓고있다! 소들은 자신들이 가지고 있는 돈을 활용해서 최대한 재밌는 롤러코스터를 만들고 싶어한다.
롤러코스터는 직선형으로, 길이가 L이다. 소들이 롤러코스터를 지을 때, 롤러코스터는 N개의 교체 가능한 부품들중 일부로 구성되어야 한다.
각 부품 i는 고정된 길이 Wi를 가지고 있다. 그리고 다양한 지형의 굴곡 때문에, i번째 부품은 오직 Xi의 위치를 시작점으로만 놓을 수 있다.
소들은 다양한 롤러코스터를 0부터 L까지 빈틈없이 채우고 싶어한다. 만약 중간에 빈칸이 있으면 롤러코스터를 구성할 수 없다. 또한, 각 부품끼리 겹쳐서 롤러코스터를 건설하는 경우도 없다.
각 i번째 부품은 "재미도" Fi과 짓는데 드는 비용 Ci가 있다. 총 비용은 롤러코스터를 구성하는 부품을의 비용의 합으로 계산된다. 마찬가지로 총 재미도의 합은 롤러코스터를 구성하는 부품들의 재미도의 합으로 계산된다.
소들의 총 예산은 B이다. 소들을 도와 예산내에서 가장 큰 재미도를 가진 롤러코스터를 지을 수 있도록 도와주자!
 
## 입력
 
첫 번재 줄에 세개의 정수 L, N, B가 공백으로 분리되어 주어진다. (1 ≤ L ≤ 1,000, 1 ≤ N ≤ 10,000, 1 ≤ B ≤ 1,000)
두 번째 줄부터 N개의 줄에 걸쳐 각 부품들의 Xi, Wi, Fi, Ci가 공백으로 분리되어 주어진다. (0 ≤ Xi ≤ L-Wi, 1 ≤ Wi ≤ L, 1 ≤ Fi ≤ 1,000,000, 1 ≤ Ci ≤ 1,000)
 
## 출력
 
첫 번째 줄에 소들이 예산안에 각 부품들을 가지고 지을 수 있는 롤러코스터의 최대 재미도의 합을 출력한다. 만약, 롤러코스터를 짓는 방법이 없다면 -1을 출력한다.
 
## 예제 입력
 
5 6 10
0 2 20 6
2 3 5 6
0 1 2 1
1 1 1 3
1 2 5 4
3 2 10 2
 
## 예제 출력
 
17
 
## 예제 설명
3번, 5번, 6번 부품들을 이용하면 롤러코스터는 비용 7을 이용해서 재미도 17의 롤러코스터를 만들 수 있다. 반면, 1번, 2번 부품들을 이용하면 재미도는 25이지만 비용이 12가 되어 예산(10)을 초과하게 된다.
 
## 힌트
Napsack Algorithm
 
 
*/
 
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
 
typedef struct _part {
    int start;
    int end;
    int len;
    int fun;
    int cost;
}part;
 
unsigned long long fun[1001][1001];
vector<part> parts;
 
bool cmp(part a, part b) {
    return (a.start < b.start);
}
 
int main(void) {
    int L, N, B;
 
    memset(fun, 0x00, sizeof(fun));
 
    scanf("%d%d%d", &L, &N, &B);
 
    for (int i = 0; i < N; ++i) {
        part temp;
        scanf("%d%d%d%d", &(temp.start), &(temp.len), &(temp.fun), &(temp.cost));
        temp.end = temp.start + temp.len;
        parts.push_back(temp);
    }
 
    sort(parts.begin(), parts.end(), cmp);
 
    for (int i = 0; i < N; ++i) {
        if (parts.front().start == 0) {
            fun[parts.front().len][B - parts.front().cost] = parts.front().fun;
            parts.erase(parts.begin());
        }
    }
 
    for (vector<part>::iterator iter = parts.begin(); iter != parts.end(); ++iter) {
        for (int b = 0; b <= B; ++b) {
            if (fun[iter->start][b] == 0) {
                continue;
            }
            else {
                if (B - (iter->cost) >= 0) {
                    fun[iter->end][b - (iter->cost)] = max(iter->fun + fun[iter->start][b], fun[iter->end][b - iter->cost]);
                }
            }
        }
    }
 
    unsigned long long result = 0;
 
    for (int i = 0; i <= B; ++i) {
        if (fun[L][i] > result) {
            result = fun[L][i];
        }
    }
 
    if (result == 0) {
        printf("-1\n");
    }
    else {
        printf("%llu\n", result);
    }
 
}