/********************************************************************************
## 문제
우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한 문화를 가지고 있다. 이런한 촌수는 다음과 같은 방식으로 계산된다.
기본적으로 부모와 자식 사이를 1촌으로 정의하고, 이로부터 사람들 간의 촌수를 계산한다. 예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로
나와 할아버지는 2촌이 되고, 아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.
여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.

## 입력
첫 번째 줄에 전체 사람의 수 N이 주어진다. 사람들의 번호는 각각 1, 2, ..., N으로 표현된다. (1 ≤ N ≤ 100)
두 번째 줄에 촌수를 계산해야 하는 서로 다른 두 사람의 번호 A, B가 주어진다.(1 ≤ A, B ≤ N)
세 번째 줄에 부모 자식들 간의 관계의 개수 M이 주어진다.
네 번째 줄부터 M개의 줄에 걸쳐 부모 자식간의 관계를 나타내는 두 번호 x, y가 공백으로 분리되어 주어진다. 이 때, x는 y의 부모임을 나타낸다. (1 ≤ x, y ≤ N)

## 출력
첫 번째 줄에 A, B 간의 촌수를 출력한다. 어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있는데, 이 때에는 -1을 출력한다.

## 예제 입력

9
7 3
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6

## 예제 출력

3

********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

int parents[101];
vector<int> grand_parents_a;
vector<int> grand_parents_b;
int cnt_a;
int cnt_b;
int person_a;
int person_b;
int N, M;

void search_grand_parents_a(int person) {
	grand_parents_a.push_back(person);

	int p = person;
	while (parents[p] != 0) {
		grand_parents_a.push_back(parents[p]);
		p = parents[p];
	}
}

void search_grand_parents_b(int person) {
	grand_parents_b.push_back(person);

	int p = person;
	while (parents[p] != 0) {
		grand_parents_b.push_back(parents[p]);
		p = parents[p];
	}
}

int main(void) {
	memset(parents, 0x00, sizeof(parents));
	scanf("%d", &N);

	scanf("%d%d", &person_a, &person_b);

	scanf("%d", &M);

	for (int i = 0; i < M; ++i) {
		int parent, son;
		scanf("%d%d", &parent, &son);
		parents[son] = parent;
	}

	search_grand_parents_a(person_a);

	// for(int i=0; i<grand_parents_a.size(); ++i){
	// 	printf("%d ", grand_parents_a[i]);
	// }
	// printf("\n");

	search_grand_parents_b(person_b);

	// for(int i=0; i<grand_parents_b.size(); ++i){
	// 	printf("%d ", grand_parents_b[i]);
	// }
	// printf("\n");

	int result = 0;
	if (grand_parents_a[grand_parents_a.size() - 1] == grand_parents_b[grand_parents_b.size() - 1]) {
		while ((grand_parents_a.size() >= 1) && (grand_parents_b.size() >= 1) && (grand_parents_a[grand_parents_a.size() - 1] == grand_parents_b[grand_parents_b.size() - 1])) {
			grand_parents_a.pop_back();
			grand_parents_b.pop_back();
		}
		result += grand_parents_a.size();
		result += grand_parents_b.size();

		printf("%d\n", result);

	}
	else {
		printf("-1\n");
	}

	return 0;
}