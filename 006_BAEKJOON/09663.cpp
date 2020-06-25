/*
## 문제
 
N-Queen문제는 유명한 문제이다. 이는 N × N인 체스판 위에 N개의 퀸을 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하시오.
 
## 입력
 
첫 번째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 12)
 
## 출력
 
첫 번째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
 
## 예제 입력
4
 
## 예제 출력
2
*/
 
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#include <math.h>
 
 
int column[13] = { 0, };
int result = 0;
int N;
 
int capable(int i) {
    int k = 1, capable = 1;
 
    while (k < i && capable) {
        if ((column[k] == column[i]) || (abs(column[i] - column[k]) == abs(i - k)))
            capable = 0;
        k++;
    }
 
    return capable;
 
}
 
void nqueens(int i) {
    int j;
 
    if (capable(i)) {
        if (i == N) {
            result += 1;
        }
        else {
            for (j = 1; j <= N; ++j) {
                column[i + 1] = j;
                nqueens(i + 1);
            }
        }
    }
}
 
int main(void) {
    scanf("%d", &N);
    nqueens(0);
    printf("%d\n", result);
}