/********************************************************************************
## 문제
최근에 지은이는 건축에 관심이 많아 집을 짓게 되었다. 태양이는 지은이가 지은 집에 놀러갔다. 근데 아니나 다를까 집에 작은 구멍이 있는 것이다. 지은이와 태양이는 집을 보수하기로 했다.
다행히도 지은이가 집을 짓다가 남은 재료가 남아서, 이를 이용하여 집을 보수하기로 했다. 구멍이 난 곳의 너비는 x센티미터이다. 태양이와 지은이는 사이가 너무 좋아서, 남은 재료 중 하나씩 골라서 이어 붙이고, 이로 구멍을 막기로 했다. 즉, 태양이과 지은이가 고른 재료의 길이가 L1, L2이면, L1+L2가 x와 같아야 구멍을 막을 수 있다. 크기가 다르면, 또 망가질 위험이 있기 때문이다.
그럼 이제 구멍을 완벽하게 막을 수 있는 두 막대를 구하는 프로그램을 작성하시오.

## 입력
첫 번째 줄에 구멍의 너비 X가 주어진다. X의 단위는 센티미터이다.
두 번째 줄에 재료의 개수 N이 주어진다. (0 ≤ N ≤ 1,000,000)
세 번째 줄부터 N개의 줄에 걸쳐 각 재료의 길아 Li가 주어진다. Li의 단위는 나노미터이다. (1 ≤ Li ≤ 100,000,000, 1cm = 10,000,000nm)

출력
첫 번째 줄에 구멍을 완벽하게 막을 수 있는 두 조각이 없다면 'danger'(따옴표 제외)를 줄력한다. 만약, 완벽하게 막을 수 있는 경우 'yes L1 L2'를 출력한다. (L1 ≤ L2). 정답이 여러 개인 경우에는 |L1 - L2|가 가장 큰 것을 출력한다.

힌트
예제 입력

1
4
9999998
1
2
9999999
예제 출력

yes 1 9999999


## 정렬을 했다면 이분탐색..
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> parts;
int X;
int N;

int search_couple(int searchItem) {
	int low = 0;
	int high = N - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (parts[mid] < searchItem) {
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}

	if(parts[high+1] == searchItem) return high+1;
	return -1;
}

int main(void) {
	int temp;
	scanf("%d", &X);
	X *= 10000000;
	scanf("%d", &N);
	int max_gap = 0;
	int part1, part2;
	bool isFound = false;
	int searchIdx;

	if (X > 200000000 || N == 0) {
		printf("danger\n");
		return 0;

	}

	for (int i = 0; i < N; ++i) {
		scanf("%d", &temp);

		parts.push_back(temp);
	}

	sort(parts.begin(), parts.end());

	for (int i = 0; i < N; ++i) {
		if(parts[i] * 2 == X){
			if(parts[i] == parts[i+1]){
				part1 = parts[i];
				part2 = parts[i+1];
				isFound = true;
				break;
			}
		}
		else if ((searchIdx = search_couple(X - parts[i])) >= 0) {
			part1 = parts[i];
			part2 = X - parts[i];
			isFound = true;
			break;
		}

	}

	if (isFound == false) {
		printf("danger\n");
	}
	else {
		printf("yes %d %d\n", part1, part2);
	}

	return 0;
}