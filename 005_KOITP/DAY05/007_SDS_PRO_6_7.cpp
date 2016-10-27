/********************************************************************************
## 문제
일렬로 놓인 짐칸에는 서로 다른 무게를 갖는 짐이 한 칸에 하나씩 놓여 있다. 가장 앞에 위치한 짐칸에 가장 가벼운 짐이 놓이고 
이어 무게 순서대로 짐이 놓여 가장 마지막에 위치한 짐칸에는 가장 무거운 짐이 놓이도록 짐칸을 정리하려 한다. 
짐을 옮길 때는 두 짐의 위치를 서로 바꾸어 주어야 하며, 이 때 두 짐의 무게의 합만큼의 힘이 든다.
짐칸의 개수와 짐칸에 놓인 짐의 무게가 차례대로 주어질 때 짐칸을 정리하기 위해 필요한 최소 힘을 구하는 프로그램을 작성하시오.
예를 들어, 무게가 각각 10, 2, 8, 5인 네 개의 짐이 짐칸에 차례로 놓여 있다고 하자. 
무게가 10인 짐과 무게가 2인 짐의 위치를 서로 바꾸어 주고, 이어 무게가 10인 짐과 무게가 5인 짐의 위치를 서로 바꾸어 주면 짐칸 정리를 마치게 된다. 
이 때 드는 총 힘은 아래와 같이 (10+2) + (10+5) = 27 이 된다.

10 2 8 5
----------- 2 + 10 = 12만큼 힘이 든다.
2 10 8 5
----------- 5 + 10 = 15만큼 힘이 든다.
2 5 8 10

최종적으로 12 + 15 = 27만큼 힘이 든다.
반면 먼저 무게가 2인 짐과 5인 짐의 위치를 서로 바꾸어 주고, 이어 무게가 10인 짐과 2인 짐의 위치를 서로 바꾸어 주어도 짐칸이 정리된다. 
이렇게 했을 때 드는 총 힘은 아래와 같이 (2+5) + (10+2) = 19 가 된다.

10 2 8 5
----------- 2 + 5 = 7만큼 힘이 든다.
10 5 8 2
----------- 2 + 10 = 12만큼 힘이 든다.
2 5 8 10

최종적으로 7 + 12 = 19만큼 힘이 든다.

## 입력
첫 번째 줄에 짐칸의 수 N이 주어진다. (1 ≤ N ≤ 1,000)
두 번째 줄부터 N개의 줄에 걸쳐 한 줄에 하나씩 짐의 무게가 차례대로 주어진다. 모든 짐의 무게는 서로 다르고, 각 짐의 무게는 1 이상 10,000 이하이다.

## 출력
첫 번째 줄에 짐칸을 정리하기 위해 필요한 최소 힘을 출력한다.

## 예제 입력

4 
10 
2 
8 
5

## 예제 출력

19
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	

	return 0;
}