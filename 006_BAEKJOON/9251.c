#include <stdio.h>
#include <string.h>

#define MAX(A,B) ((A)>(B))?(A):(B)


int main(){
  char str1[1001];
  char str2[1001];
  int dp[1001][1001];

  memset(dp, 0x00, sizeof(dp));

  scanf("%s%s", str1, str2);

  int len_str1 = strlen(str1);
  int len_str2 = strlen(str2);

  for(int i=1; i<=len_str1; ++i){
    for(int j=1; j<=len_str2; ++j){
      if(str1[i-1] == str2[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else {
        dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  printf("%d\n", dp[len_str1][len_str2]);

  return 0;
}