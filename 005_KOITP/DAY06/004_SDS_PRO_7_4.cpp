/********************************************************************************
문제
아래와 같이 여러개의 정사각형칸들로 이루어진 정사각형 모양의 종이가 주어져 있고, 각 정사각형들은 0으로 칠해져 있거나 1로 칠해져 있다.
주어진 종이를 일정한 규칙에 따라 잘라서 다양한 크기를 가진 정사각형 모양의 0 또는 1로 칠해진 색종이를 만들려고 한다.

11000011
11000011
00001100
00001100
10001111
01001111
00111111
00111111
전체 종이의 크기가 N×N(N=2^k, k는 1 이상 7 이하의 자연수) 이라면 종이를 자르는 규칙은 다음과 같다.

전체 종이가 모두 같은 색으로 칠해져 있지 않으면 가로와 세로로 중간 부분을 잘라서 똑같은 크기의 네 개의 N/2 × N/2색종이로 나눈다.
나누어진 종이 I, II, III, IV 각각에 대해서도 앞에서와 마찬가지로 모두 같은 색으로 칠해져 있지 않으면 같은 방법으로 똑같은 크기의 네 개의 색종이로 나눈다.
이와 같은 과정을 잘라진 종이가 모두 0 또는 모두 1으로 칠해져 있거나, 하나의 정사각형 칸이 되어 더 이상 자를 수 없을 때까지 반복한다.
입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(0 또는 1)이 주어질 때 잘린 조각들 중 0으로 칠해진 색종이의 수와 1로 칠해진 색종이의 개수를 구하는 프로그램을 작성하시오.

## 입력
첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다. N은 2, 4, 8, 16, 32, 64, 128 중 하나이다. 색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다.
각 숫자 사이에는 빈칸이 하나씩 있다.

## 출력
첫째 줄에는 잘라진 색종이들 중 0으로 칠해진 색종이의 수를 출력하고, 두 번째 줄에는 잘린 색종이들 중 1로 칠해진 색종이의 수를 출력하라.

## 예제 입력
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1

## 예제 출력
9
7

## 분할 정복
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int map[129][129];
int cnt_0 = 0;
int cnt_1 = 0;

int get_sum(int start_x, int start_y, int end_x, int end_y){
	int sum = 0;
	for(int i=start_x; i<=end_x; ++i){
		for(int j=start_y; j<=end_y; ++j){
			sum += map[i][j];
		}
	}
	return sum;
}

void solve(int start_x, int start_y, int end_x, int end_y) {
	int check = get_sum(start_x, start_y, end_x, end_y);

	if(check == 0){
		cnt_0 += 1;
		return;
	}
	if(check == (end_x-start_x+1) * (end_y-start_y+1)){
		cnt_1 += 1;
		return;
	}
	int mid_x = (start_x + end_x) / 2;
	int mid_y = (start_y + end_y) / 2;

	solve(start_x, start_y, mid_x, mid_y);
	solve(mid_x+1, start_y, end_x, mid_y);
	solve(start_x, mid_y+1, mid_x, end_y);
	solve(mid_x+1, mid_y+1, end_x, end_y);
}

int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			char temp[2];
			scanf("%s", temp);
			map[i][j] = temp[0] - '0';
		}
	}

	solve(1, 1, N, N);

	printf("%d\n%d\n", cnt_0, cnt_1);


	// for (int i = 1; i <= N; ++i) {
	// 	for (int j = 1; j <= N; ++j) {
	// 		printf("%d ", map[i][j]);
	// 	}
	// 	printf("\n");
	// }




	return 0;
}