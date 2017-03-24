#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

typedef struct _candle {
  int limit;
  int duration;
} candle;

typedef struct _duration {
  int from;
  int to;
}duration;

int T, N;
candle candles[1000001];
int durations[1000001];
char checked[100000001];

bool candle_comp(candle a, candle b){
  return (a.limit + a.duration) < (b.limit + b.duration);
}

int solve(){
  int retVal = candles[0].duration;
  int duration_cnt = 1;
  durations[0] = candles[0].duration;
  checked[durations[0]] = 1;


  for(int i=1; i<N; ++i){
    int inc = 0;
    for(int j=0; j<duration_cnt; ++j){
      if(candles[i].limit >= durations[j]){
        if(checked[durations[j] + candles[i].duration] == 0){
          durations[duration_cnt+inc] = durations[j] + candles[i].duration;
          if(durations[duration_cnt+inc] > retVal){
            retVal = durations[duration_cnt+inc];
          }
          checked[durations[duration_cnt+inc]] = 1;
          ++inc;
        }
      }
    }
    if(checked[candles[i].duration] == 0){
      durations[duration_cnt+inc] = candles[i].duration;
      if(durations[duration_cnt+inc] > retVal){
        retVal = durations[duration_cnt+inc];
      }
      checked[durations[duration_cnt+inc]] = 1;
      ++inc;
    }
    duration_cnt += inc;
  }
  return retVal;
}

int main(void)
{
  scanf("%d", &T);

  for(int tc=1; tc<=T; ++tc){
    scanf("%d", &N);

    memset(candles, 0x00, sizeof(candles));
    memset(durations, 0x00, sizeof(durations));
    memset(checked, 0x00, sizeof(checked));

    for(int i=0; i<N; ++i){
      scanf("%d%d", &(candles[i].limit), &(candles[i].duration));
    }

    sort(candles, candles+N, candle_comp);

    printf("#%d %d\n", tc, solve());
  }

  return 0;
}
