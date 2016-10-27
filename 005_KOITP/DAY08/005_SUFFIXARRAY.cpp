/********************************************************************************
## 문제
접미사 배열이란 전산학에서 어떤 문자열의 접미사를 사전식 순서대로 나열한 배열을 말한다.
예를 들면, FOOD의 접미사는 FOOD, OOD, OD, D 로 총 4가지가 있고 접미사 배열은 총 4가지의 접미사를 사전순으로 나열한 것이므로 다음과 같다. D, FOOD, OD, OOD

## 입력
첫 번째 줄에 문자열이 주어진다. 주어지는 문자열은 알파벳 대문자로만 구성되며, 길이는 1,000 이하이다.

## 출력
입력으로 주어진 문자열의 접미사 배열을 한줄에 하나씩 출력하라.

## 힌트
## 예제 입력

FOOD

## 예제 출력

D
FOOD
OD
OOD

## 풀이
- 원래대로라면 O(N^2logN)의 시간이 걸리나 O(NlogN)의 방법이 존재
- counting sort
********************************************************************************/


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct _suf{
	char suffix[1001];
}suf;

suf list[1001];

bool cmp(suf a, suf b){
	int min = std::min(strlen(a.suffix), strlen(b.suffix));
	int ret = strncmp(a.suffix, b.suffix, min);
	if(ret > 0){
		return false;
	}
	else if (ret < 0){
		return true;
	}
	else {
		return strlen(a.suffix) < strlen(b.suffix);
	}
}

int main(void){
	char input[1001];
	int len;

	scanf("%s", input);
	len = strlen(input);

	for(int i=0; i<len; ++i){
		strcpy(list[i].suffix, input+i);
	}

	sort(list, list+len, cmp);

	for(int i=0; i<len; ++i){
		printf("%s\n", list[i].suffix);
	}

	return 0;
}