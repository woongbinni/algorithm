/********************************************************************************
## 문제

길이 N의 수열이 주어진다. 이 수열의 초기값은 1, 2, 3, ..., N이다. 그런데 이 수열의 변경이 빈번히 일어나고, 그런 도중에 어떤 연속된 부분의 합을 구하려 한다.
만약 N이 5인 경우를 생각하자. 초기에는 1, 2, 3, 4, 5 가 된다. 이 상황에서 3번째 수를 9로 변경하고 4번째 수를 10으로 변경하면 1, 2, 9, 10, 5가 된다.
이 때, 2번째부터 5번째까지 합을 구하라고 한다면 26을 출력하면 되는 것이다. 또, 이 상태에서 1번째 수를 -5로 변경하고, 3번째 수를 5로 변경하면 -5, 2, 5, 10, 5가 된다.
그 다음, 1번째부터 3번째까지 합을 구하라고 한다면 2가 된다.
이러한 질의를 해결하는 프로그램을 작성하시오.

## 입력

첫 번째 줄에 정수의 개수 N이 주어진다. (1 ≤ N ≤ 100,000)
두 번째 줄에 질이의 개수 Q가 주어진다. (1 ≤ Q ≤ 200,000)
세 번째 줄부터 Q개의 줄에 걸쳐 질의의 정보가 주어진다. 각 질의는 다음 형태로 이루어진다.
0 x y : x번째 수를 y로 변경한다. (1 ≤ x ≤ N, -100,000 ≤ y ≤ 100,000)
1 x y : x번째 수부터 y번째 수까지의 합을 구한다. (1 ≤ x ≤ y ≤ N)

## 출력
질의 중 1로 시작하는 질의에 대해, 구한 합을 한 줄에 하나씩 출력한다. 이 때, 답의 범위가 32-bit 정수형의 범위를 초과할 수 있음에 유의하여라.

## 입력 예제

5
7
1 2 4
0 3 9
0 4 10
1 2 5
0 1 -5
0 3 5
1 1 3

## 출력 예제

9
26
2

## 힌트 : Indexd Tree
void Update(int v, int k){
	Tree[v] = k;
	while(v!= 1){
	v/= 2;
	Tree[v] = Tree[v*2] + Tree[v*2+1];
	}
}

ll Get Sum(int a, int b){
	ll result == 0;
	while(a <= b){
	if(a%2 == 1) result += Tree[a++];
	if(b%2 == 0) result += Tree[b--];
	a/=2;
	b/=2;
	}
	return result;
}
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long tree[300000];
int N, Q;
int pivot_num;

void tree_update(int v, int k) {
    tree[v] = k;
    while (v != 1) {
        v /= 2;
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    return;
}

long long get_sum(int a, int b) {
    long long result = 0;
    while (a <= b) {
        if (a % 2 == 1) result += tree[a++];
        if (b % 2 == 0) result += tree[b--];
        a /= 2;
        b /= 2;
    }
    return result;
}

int main(void) {
    int pivot = 0;
    scanf("%d", &N);

    memset(tree, 0x00, sizeof(tree));
    while ((1 << pivot) < N) {
        pivot++;
    }
    pivot_num = 1 << pivot;

    int num=1;
    for (int i = pivot_num; i < pivot_num + N; ++i) {
        tree_update(i, num++);
    }

    scanf("%d", &Q);

    for(int i = 0; i<Q; ++i){
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);

        if(type == 0){
            tree_update(pivot_num+x-1, y);
        }
        else {
            printf("%lld\n", get_sum(pivot_num+x-1, pivot_num+y-1));
        }
    }
    return 0;
}