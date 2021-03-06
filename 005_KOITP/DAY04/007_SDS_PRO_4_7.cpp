/********************************************************************************
## 문제
삼성 SDS 체력단련장에는 각기 다른 무게를 가진 N 개의 역기들이 고정대 위에 놓여있다.
아침에는 체력단련장 이용자들의 편의를 위하여 바벨들을 무게순으로 정렬하여 둔다.
하지만, 체력 단련장이 문을 닫을 때가 되면 , N 개의역기들은 무게 순과는 무관하게 어지럽게 놓여져 있다.
체력단련장 관리자인 동현이는 체력단련장의 문을 닫으면서 어지럽게 놓인 N 개의 역기들을 무게의 오름차순으로 정렬하는 일을 담당하고 있다.
역기의 무게가 만만치 않기 때문에 동현이는 들어 옮기는 역기의무게의 합을 최소로 하여 정렬하고자 한다.
안전을 위하여 동현이는 한 번에 두 개의 역기를 들어 옮기지는 않는다. 옮기는 바벨이 꼭 인접해 있을 필요는 없다.
들어올리는 무게의 합이 최소로 되도록 바벨들을 정렬할 때 , 그 때의 무게 합을 구하는 프로그램을 작성하시오.

시간제한 : 1초

## 입력
첫 줄에 역기의 개수 N 이 10,000 이하인 양의 정수로 주어지고 , 다음 줄 부터 역기들의 무게(Wi <= 100,000) 가 주어진다. 역기들의 무게는 서로 다르다.

## 출력
오름차순으로 역기들을 정렬하기 위하여 옮겨야 하는 무게의 합의 최소값을 출력한다.

## 입력 예제
3
2
3
1

## 출력 예제
7

## 설명
2 3 1 : 초기 상태
2 1 3 : 1과 3의 위치를 바꿈 (4 = 1 + 3)
1 2 3 : 1과 2의 위치를 바꿈 (3 = 1 + 2)

따라서 들어올리는 무게의 합은 7이며, 이때가 최소이다.


ans += sum + (n-2)min
super min = (super min + min) * 2

********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	

	return 0;
}