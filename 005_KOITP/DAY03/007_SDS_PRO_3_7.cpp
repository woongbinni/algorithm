/********************************************************************************
## 문제
주어지는 K개의 소수만을 인수로 가지는 숫자들 중 1을 제외한 숫자들을 '소수들의 곱셈'이라고 정의하자. 주어지는 소수가 2, 3, 5, 7인 경우 이런, 
'소수들의 곱셈'에는 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27 등이 있다.
K개의 소수가 주어졌을 때 N번째 '소수들의 곱셈'을 알아내는 프로그램을 작성하자.

## 입력
첫 번째 줄에 주어지는 소수의 개수 K가 주어진다. (1 ≤ K ≤ 100)
두 번째 줄에 N이 주어진다. (1 ≤ N ≤ 100,000)
세 번째 줄부터 K개의 줄에 걸쳐 소수가 주어진다. (2 ≤ 소수 ≤ 1,000,000)

## 출력
첫 번째 줄에 K개의 소수로 만들 수 있는 N번째 '소수들의 곱셈'을 출력한다. 답은 항상 부호 있는 32-bit 정수형 이내에 있다.

## 입력 예제

4 
23
2
3
5
7

## 출력 예제

35
********************************************************************************/


#include <stdio.h>
#include <algorithm>
using namespace std;
int k, n, r[100001], p[100], idx[100];
long long nxt[100];
int main(){
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++){
        scanf("%d", &p[i]);
        nxt[i] = p[i];
    }
    r[0] = 1;
    for (int i = 1; i <= n; i++){
        long long mini = *min_element(nxt, nxt + k);
        r[i] = mini;
        for (int j = 0; j < k; j++)
            if (nxt[j] == mini)
                nxt[j] = (long long)p[j] * r[++idx[j]];
    }
    printf("%d\n", r[n]);
    return 0;
}
