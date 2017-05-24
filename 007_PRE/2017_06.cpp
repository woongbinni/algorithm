#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

int T, N, M, K;
vector<unsigned long long> power_station[100001];
unsigned long long result;

int main(void){
    scanf("%d", &T);

    for(int tc=1; tc<=T; ++tc){
        scanf("%d%d%d", &N, &M, &K);
        result = 0;
        for(int i=0; i<=K; ++i){
            power_station[i].clear();
        }

        for(int i=1; i<=K; ++i){
            int in;
            scanf("%d", &in);
            power_station[in].push_back(i);
        }

    


        printf("#%d %llu", tc, result);
    }

    return 0;
}