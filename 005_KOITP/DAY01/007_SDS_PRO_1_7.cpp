/*
## 문제
최근 출시된 오버워치가 지루해진 형석이는 등산이나 하기로 결정했다. 형석이는 산의 시작점부터 도착지점까지 산을 오르락~ 내리락~ 하면서 간다. 하지만 형석이는 몸이 허약하여, 하루동안 급변한 고도의 변화를 느끼면 어지러움과 함께, 구토를 하며 쓰러진다.
형석이는 이런 증상을 최소화하기 위해, 경로 중 가장 높은 지점과, 가장 낮은 지점의 고도차가 가장 작게 등산 경로를 정하려고 한다. 하지만 등산 준비로 바쁜 형석이는 당신에게 이 문제를 부탁하였다.
산은 N*N의 크기로 이루어져 있다. 형석이는 (1,1)을 시작점으로, (N,N)을 도착점으로 정하였다. 또한 형석이는 상, 하, 좌, 우의 인접한 칸으로 이동할 수 있다. 가능한 형석이의 등산 경로 중, 가장 높은 지점과 낮은 지점의 차가 최소가 되는 경우의 그 값을 구하여라.
시간제한: 1초

## 입력
첫째 줄에 N(2<=N<=100)이 주어진다. 다음 N개의 줄에는 배열이 주어진다. 배열의 각 수는 0보다 크거나 같고, 200보다 작거나 같은 정수이다.

## 출력
첫째 줄에 경로 중 고도의 최대와 최소의 차가 가장 작아질 때의 그 값을 출력하세요.

## 입력 예제
5
1 1 3 6 8
1 1 8 5 6
8 10 0 4 3
8 0 2 3 4
4 3 0 2 1

##출력 예제
5

*/

/*

//Depa Code
#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int arr[102][102];
int arr2[102][102];
vector<int> v[10001];

vector<pair<int, int>> pv;
int pvIdx[10001];
int q[1000001];
int rear = 0, front = 0;

int check[10001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    int M,N;
    
    scanf("%d%d", &M,&N);
    
    memset(arr, -1, sizeof(arr));
    memset(arr2, -1, sizeof(arr2));
    
    for(int i = 1; i<=M; i++){
        for(int j = 1; j<=N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    int group = 0;
    int cp = 0, row, col;
    for(int i = 1; i<=M; i++){
        for(int j = 1; j<=N; j++){
            if(arr2[i][j] == -1){
                cp = arr[i][j];
                ++group;
                
                rear = 0;
                front = 0;
                
                q[++rear] = i;
                q[++rear] = j;
                arr2[i][j] = group;
                
                while(rear - front){
                    row = q[++front];
                    col = q[++front];
                    
                    for(int d = 0; d < 4; ++d){
                        if(arr[row + dy[d]][col + dx[d]] == cp && arr2[row + dy[d]][col + dx[d]] == -1) {
                            q[++rear] = row+dy[d];
                            q[++rear] = col+dx[d];
                            arr2[row + dy[d]][col + dx[d]] = group;
                        } else if(arr2[row + dy[d]][col+ dx[d]] != -1 && arr2[row][col] != arr2[row + dy[d]][col+ dx[d]]){
                            pv.push_back(make_pair(arr2[row + dy[d]][col + dx[d]], arr2[row][col]));
                            pv.push_back(make_pair(arr2[row][col], arr2[row + dy[d]][col + dx[d]]));
                        }
                    }
                }
            }
        }
    }
    
    sort(pv.begin(), pv.end());
    pv.erase(unique(pv.begin(), pv.end()), pv.end());
    
    int pvSize = (int)pv.size();
    for(int i = 0; i < pvSize; ++i){
        pvIdx[pv[i].first] = i+1;
    }
    
    int limit = M*N;
    limit = limit / 4;
    int min = 0x7fffffff;
    int cnt = 0;
    int hg = group/2;
    int acnt = 0;
    for(int i = hg; i <= group; ++i){
        if(++acnt > limit) break;
        cnt = -1;
        memset(check, 0, sizeof(check));
        
        rear = 0;
        front = 0;
        q[++rear] = i;
        check[i] = 1;
        int size = rear - front;
        
        while(size){
            cnt++;
            if(cnt >= min) break;
            for(int j = 0; j < size; ++j){
                int a = q[++front];
                for(int k= pvIdx[a-1] ; k < pvIdx[a]; ++k){
                    if(!check[pv[k].second]){
                        check[pv[k].second] = 1;
                        q[++rear] = pv[k].second;
                    }
                }
            }
            size = (int)rear - front;
        }
        min = min > cnt ? cnt : min;
    }
    
    acnt = 0;
    for(int i = hg -1; i >=1 ; --i){
        if(++acnt > limit) break;
        cnt = -1;
        memset(check, 0, sizeof(check));
        
        rear = 0;
        front = 0;
        q[++rear] = i;
        check[i] = 1;
        int size = rear - front;
        
        while(size){
            cnt++;
            if(cnt >= min) break;
            for(int j = 0; j < size; ++j){
                int a = q[++front];
                for(int k= pvIdx[a-1] ; k < pvIdx[a]; ++k){
                    if(!check[pv[k].second]){
                        check[pv[k].second] = 1;
                        q[++rear] = pv[k].second;
                    }
                }
            }
            size = (int)rear - front;
        }
        min = min > cnt ? cnt : min;
    }
    printf("%d\n", min);
    
    return 0;
}

*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int map[101][101];
int max_val = 0;
int min_val = 0x7FFFFFFF;

int solve(int gap){
	return gap/2;
}

int main()
{
    int i, j;
 
    scanf("%d", &n);
 
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
 
            if (map[i][j] < min_val)    min_val = map[i][j];
            if (map[i][j] > max_val)    max_val = map[i][j];
        }
    }
 
    printf("%d\n", solve(max_val - min_val));
 
    return 0;
}