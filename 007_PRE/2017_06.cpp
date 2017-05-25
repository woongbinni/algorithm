#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int T, N, M, K;
unsigned long long result;
vector<unsigned long long> power_station[100001];
int machine_on[100001];

int main(void){
    scanf("%d", &T);

    for(int tc=1; tc<=T; ++tc){
        scanf("%d%d%d", &N, &M, &K);
        result = 0;
        memset(machine_on, 0x00, sizeof(machine_on));

        for(int i=1; i<=M; ++i){
            power_station[i].clear();
        }

        for(int i=1; i<=K; ++i){
            int in;
            scanf("%d", &in);
            power_station[in].push_back(i);
        }

        for(int i=1; i<=M; ++i){
            for(int j=0; j<power_station[i].size(); ++j){
                printf("%d ", power_station[i][j]);
            }
            printf("\n");
        }


        for(int i=1; i<=N; ++i){
            int ps1, ps2, ps3, need;
            int on1, on2, on3;
            scanf("%d%d%d%d", &ps1, &ps2, &ps3, &need);

            if(power_station[ps1].size() < need){
                on1 = K+1;
            }
            else{
                on1 = power_station[ps1][need-1];
            }

            if(power_station[ps2].size() < need){
                on2 = K+1;
            }
            else{
                on2 = power_station[ps2][need-1];
            }

            if(power_station[ps3].size() < need){
                on3 = K+1;
            }
            else{
                on3 = power_station[ps3][need-1];
            }

            int min_val = min(on3, min(on1, on2));

            machine_on[min_val] += 1;
        }

        int sum = 0;

        for(int i=1; i<=K; ++i){
            printf("%d ", machine_on[i]);
            sum += machine_on[i];
            result += (i * sum);

            result %= 100000123;
        }
        printf("\n");

        printf("#%d %llu\n", tc, result);
    }

    return 0;
}