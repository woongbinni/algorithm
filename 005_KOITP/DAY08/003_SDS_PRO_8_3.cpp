/********************************************************************************
## 문제
취직에 관심이 없던 정래는 실력을 올릴 필요성을 못느꼈고, 문제를 푸는걸 기피했다. 하지만 삼성 SDS교육을 듣고난 이후, 
정래에게는 꿈이생겼다. 그건 바로 SDS에 취직을 하는것이다!
정래가 SDS에 들어가기 위해서는 정확히 P(1 ≤ P ≤ 300)개의 문제를 순서대로 풀어야지만 들어갈 수 있었다. 
하지만 너무 오랫동안 문제푸는 일을 소홀히 했던 정래는 단 한문제도 자기힘으로 해결할 수 없었다. 그래서 정래는 
매일 열심히 문제를 풀어온 창수에게 도움을 요청했다. 예전에는 정래와 비슷한 실력이었던 창수는 매일매일 열심히 연습해서 어떤 문제든, 
아무리 많은 문제를 맡든 상관없이 맡은 모든 문제들을 정확히 한달만에 풀어낼 수 있게 되었다.
열심히 연습을 해온 창수는 정래에게 사례금을 요청했다. 다행히도, 매달 정래는 평소 부모님한테 용돈을 M(1 ≤ M ≤ 1000)원씩 받는다. 
그러나 불행히도, 정래는 문제를 받은 그 달 용돈은 다 써버렸다.
창수는 각 문제들의 난이도가 다르니 각 i번째 문제에 대해 그 문제를 맡는날 A_i(1 ≤ A_i ≤ M)원 문제를 의뢰한 다음달에(문제를 푼 후) B_i(1 ≤ B_i ≤ M)원을 달라고 했다.
또한 패셔니스타를 꿈꾸는 정래는 매월 말의 남은 용돈에 대해 모든 돈을 인터넷 쇼핑으로 다 써버린다.
정래는 자신이 받은 문제들을 다 푸는데 얼마나 걸릴지 궁금해졌다. 정래가 모든 문제를 푸는데 걸리는 최소달수를 구해주자!

## 입력
첫줄에는 공백으로 분리된 두개의 자연수 M,P가 입력으로 주어진다
두번째줄부터 p+1번째 줄에는 두개의 자연수 A_i와 B_i가 공백으로 구분되어 입력되어진다.
i번째 문제는 i-1번째 문제가 풀린 이후에 의뢰해야한다.

## 출력
정래가 의뢰한 모든 문제가 해결되는 최소 월수를 출력해라.

## 예제 입력

100 5
40 20
60 20
30 50
30 50
40 40

## 예제 출력

6

## 힌트

+------+-------+--------+---------+---------+--------+
|      | Avail | Probs  | Before  |  After  | Clothes|
|Month | Money | Solved | Payment | Payment |  Money |
+------+-------+--------+---------+---------+--------+
|  1   |  0    | -none- |    0    |    0    |     0  |
|  2   | 100   |  1, 2  | 40+60   |    0    |     0  |
|  3   | 100   |  3, 4  | 30+30   |  20+20  |     0  |
|  4   | 100   | -none- |    0    |  50+50  |     0  |
|  5   | 100   |   5    |   40    |    0    |    60  |
|  6   | 100   | -none- |    0    |   40    |    60  | 
+------+-------+--------+---------+---------+--------+
********************************************************************************/


#include <stdio.h>

int main(void){

	

	return 0;
}