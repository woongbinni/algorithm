#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

typedef struct _walf_info
{
    long long max_speed;
    long long walf_cnt;
    long long distance;
} walf_info;

vector<walf_info> winfo;
long long T, x, y;

void make_info(){
    int i = 1;
    walf_info t;
    t.max_speed = i;
    t.walf_cnt = 1;
    t.distance = 1;
//    printf("%d|%d|%u\n", t.max_speed, t.walf_cnt, t.distance);
    winfo.push_back(t);
    i += 1;

    while (1)
    {
        walf_info temp;
        walf_info last = winfo.back();
        temp.max_speed = i;
        temp.walf_cnt = (2 * i) - 1;
        temp.distance = last.distance + temp.walf_cnt;
        if (temp.distance > 0x7FFFFFFF)
            break;
        winfo.push_back(temp);
//        printf("%d|%d|%u\n", temp.max_speed, temp.walf_cnt, temp.distance);

        i += 1;
    }
}

int main(void)
{
    make_info();

    scanf("%lld", &T);

    for(int tc=0; tc<T; ++tc){
        scanf("%lld%lld", &x, &y);
        long long gab = y - x;
        walf_info greedy;

        for(int i=0; i<winfo.size(); ++i){
            if(winfo[i].distance > gab){
                greedy = winfo[i-1];
                break;
            }
        }
        gab -= greedy.distance;
        int result = greedy.walf_cnt;
        if(gab != 0){
            result += (gab/greedy.max_speed);
            if((gab%greedy.max_speed)>0){
                result += 1;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}