#include <stdio.h>
#include <stdlib.h>

typedef struct _line{
  int start;
  int end;
}line;

line lines[101];
int dp[101];

int compare(const void *first, const void *second){
  if((*(line*)first).start > (*(line*)second).start){
    return 1;
  }
  else if((*(line*)first).start < (*(line*)second).start){
    return -1;
  }
  else{
    return 0;
  } 
}

int main(){
  int N;
  scanf("%d", &N);

  for(int i=1; i<=N; ++i){
    scanf("%d%d", &(lines[i].start), &(lines[i].end));
    dp[i] = 1;
  }

  qsort(&(lines[1]), N, sizeof(line), compare);

	int max = 1;

	for(int i=2; i<=N; ++i){
		for(int j=1; j<=i; ++j){
			if(lines[j].end<lines[i].end && dp[i] <= dp[j]){
				dp[i] = dp[j] + 1;
			}
		}
		if(max < dp[i]){
			max = dp[i];
		}
	}

  printf("%d\n", N-max);

  return 0;
}