/*
## 문제
0과 1로 이루어진 이진수 중 다음 성질을 만족하는 수를 이친수라고 한다.
 
이친수는 0으로 시작하지 않는다.
이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
예를 들면, 1, 10, 100 등이 이친수가 된다. 하지만 010이나 110은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다.
 
N이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.
 
## 입력
첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 90)
 
## 출력
첫 번째 줄에 N자리 이친수의 개수를 출력한다.
 
## 예제 입력
3
 
## 예제 출력
2
 
*/
 
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
unsigned long long result[91];
 
 
void solve() {
    result[1] = 1;
    result[2] = 1;
    result[3] = 2;
 
    for (int i = 4; i <= 90; ++i) {
        result[i] = result[i - 1] + result[i - 2];
    }
}
 
int main(void) {
    int T;
 
    memset(result, 0, sizeof(result));
    solve();
 
    scanf("%d", &T);
 
    printf("%llu\n", result[T]);
 
    return 0;
}
