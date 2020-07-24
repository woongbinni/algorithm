#include <iostream>
using namespace std;
#include <queue>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _num {
    int value;
    int step;
}num;
queue<num> nums;
bool visited[1000001][11];

int swap(int n, int i, int j){
    string ret = to_string(n);
    if(i==0 && ret[j] == '0') return -1;
    char temp = ret[i];
    ret[i] = ret[j];
    ret[j] = temp;
    return atoi(ret.c_str());
}

int main(){
    int N, K;
    memset(visited, false, sizeof(visited));
    scanf("%d%d", &N, &K);
    visited[N][0] = true;
    num first = {N, 0};
    nums.push(first);

    string str = to_string(N);
    int len = str.length();

    while(!nums.empty()) {
        num pop = nums.front();

        if(pop.step == K){
            break;
        }
        nums.pop();

        pop.step += 1;
        for(int i=0; i<len-1; ++i){
            for(int j=i+1; j<len; ++j){
                int change = swap(pop.value, i, j);
                if(change != -1 && visited[change][pop.step] == false){
                    visited[change][pop.step] = true;
                    num item = {change, pop.step};
                    nums.push(item);
                }
            }
        }        
    }

    int result = -1;
    while(!nums.empty()){
        if(result < nums.front().value) {
            result = nums.front().value;
        }
        nums.pop();
    }

    printf("%d\n", result);

    return 0;
}