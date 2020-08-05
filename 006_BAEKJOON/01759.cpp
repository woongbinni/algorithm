#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int L, C;
char input[16];
char password[16];
bool moum[27];

int cmp(const void * a, const void * b)
{
    return ( *(char*)a - * (char*)b );
}

void solve(int pw_count, int start_idx, int pw_point, string str){
  if(pw_count == L){
    if(pw_point >=2 && pw_point <= L-1){
      printf("%s\n", str.c_str());
    }
    return;
  } 
  if(start_idx == C){
    return;
  }
  string add_str = str + input[start_idx];
  solve(pw_count+1, start_idx+1, pw_point-(moum[input[start_idx]-'a']?1:0), add_str);
  solve(pw_count, start_idx+1, pw_point, str);

}

int main(){
  scanf("%d%d", &L, &C);
  memset(password, '\0', sizeof(password));
  memset(input, '\0', sizeof(input));
  memset(moum, false, sizeof(moum));
  moum['a'-'a'] = true;
  moum['e'-'a'] = true;
  moum['i'-'a'] = true;
  moum['o'-'a'] = true;
  moum['u'-'a'] = true;

  for(int i=0; i<C; ++i){
    char temp[2];
    scanf("%s", temp);
    input[i] = temp[0];
  }

  qsort(&(input[0]), C, sizeof(char), cmp);

  solve(0, 0, L, "");

  return 0;
}