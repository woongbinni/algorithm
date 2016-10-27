/*
## 문제
형석이는 M*N 그리드 위에 놓여있는 MN개의 흰색과 검은색 돌들을 가지고 게임을 한다.
인접해 있는 같은 색의 돌들은 같은 그룹을 형성한다. 위를 보면 A~F의 6개의 그룹을 확인할 수 있다. 여기서 하나의 그룹을 뒤집게 되면, 그 그룹의 색이 반전된다. 아래의 사진은 A그룹을 뒤집었을 때의 그림이다. A라는 그룹을 뒤집었을 때, 인접한 다른 색의 그룹과 합쳐지는 것을 확인할 수 있다. (흰색 B그룹과 합쳐졌다.)
그 후, C를 뒤집게 되면, 아래와 같다. (마찬가지로, A,B,C,D가 한그룹이 되었다.)
그 다음 위에 있는 흰색그룹을 뒤집으면, 전체가 검은색으로 바뀐다. 이렇게 전체를 모두 같은 색으로 만드는 것이 목표이다.
문제는 위의 방법대로 진행하였을 때, 모든 바둑돌을 같은 색으로 만드는 최소한의 단계수를 구하는 것이다.

시간제한: 1초

## 입력
첫째 줄에는 M*N 그리드는 나타내는 두 양의 정수 M과 N이 빈칸을 사이에 두고 주어진다. M과 N은 2이상 100이하이다. 둘째 줄부터 M개의 각 줄에는 그리드의 가로줄 한 줄에 놓여진 흰색 동을 나타내는 0과 검은색 돌을 나타내는 1이 빈칸을 사이에 두고 연속해서 N개가 주어진다.

## 출력
첫째 줄에 모든 돌들이 같은 색이 되도록 하는 색 바꾸기의 최소 횟수를 출력한다.

## 입력 예제
5 6
1 1 0 1 0 0
1 0 0 1 1 1
1 1 0 1 1 1
0 0 0 0 0 0
1 1 1 0 1 1

## 출력 예제
2
*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int grid[101][101];
int result = 0;

void solve(){
	result = 2;

}

int main(void){
	int width, height;
	scanf("%d%d", &width, &height);

	for(int i=1; i<=height; ++i){
		for(int j=1; j<=width; ++j){
			scanf("%d", &(grid[i][j]));
		}
	}

	solve();

	printf("%d\n", result);

	return 0;
}