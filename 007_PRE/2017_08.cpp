#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

int T, N;
vector<int> childNodeList[10001];
int node[10001];
char visited[10001];
int dp[10001][10001];
int maxChildCnt;
int result;

int solve(int nodeIdx, int nodeVal){
		if( dp[nodeIdx][nodeVal] != 0x7FFFFFFF){
			return dp[nodeIdx][nodeVal];
		}
				
		int childCnt = childNodeList[nodeIdx].size();
		if (childCnt == 0) {
			return dp[nodeIdx][nodeVal] = nodeVal;			
		}

		visited[nodeIdx] = 1;
		int child = 0;
		int tempVal = 0;
		int tempRet = nodeVal;
		for (int i = 0; i < childCnt; i++) {			
			child = childNodeList[nodeIdx][i];
			if( visited[child] == 1){
				continue;
			}
			tempVal = 0x7FFFFFFF;			
			for (int j = 1; j <= maxChildCnt; j++) {
				if( nodeVal == j){
					continue;
				}
				tempVal = min(solve(child, j), tempVal);				
			}		
			tempRet += tempVal;
		}

		dp[nodeIdx][nodeVal] = min(dp[nodeIdx][nodeVal], tempRet); 
		visited[nodeIdx] = 0;
		return dp[nodeIdx][nodeVal];


}

int main(void){
	scanf("%d", &T);

	for(int i=0; i<10000; ++i){
		childNodeList[i].reserve(10000);
	}

	for(int tc=1; tc<=T; ++tc){
		int root = 0;
		maxChildCnt = 0;

		scanf("%d", &N);

		for(int i=0; i<N; ++i){
			childNodeList[i].clear();
			for(int j=0; j<N; ++j){
				dp[i][j] = 0x7FFFFFFF;
			}
		}

		for(int i=0; i<N; ++i){
			scanf("%d", &(node[i]));
			if(node[i] == -1){
				root = i;
			}
			else{
				childNodeList[node[i]].push_back(i);
			}
		}

		for(int i=0; i<N; ++i){
			maxChildCnt = max(maxChildCnt, (int)childNodeList[i].size());
		}

		result = 0x7FFFFFFF;
		int rootChildCnt = childNodeList[root].size();
		for(int i=1; i<= maxChildCnt; ++i){
			memset(visited, 0x00, sizeof(visited));
			int temp = solve(root, i);
			result = min(temp, result);
		}

		printf("#%d %d\n", tc, result);
	}
	return 0;
}
