#include <iostream>
using namespace std;
#include <stdio.h>
#include <unistd.h>

int n;
bool areFriends[10][10];

int countPairings(bool *taken);

int main(void) {
  int test_case;
  int pair_cnt;
  bool friends[10];
  int a, b;
  scanf("%d", &test_case);

  for (int i = 0; i < test_case; i++) {
    scanf("%d%d", &n, &pair_cnt);
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        areFriends[j][k] = false;
      }
    }
    for (int j = 0; j < n; j++) {
      friends[j] = false;
    }
    for (int j = 0; j < pair_cnt; j++) {
      scanf("%d%d", &a, &b);
      areFriends[a][b] = areFriends[b][a] = true;
    }
    printf("%d\n", countPairings(friends));
  }
}

int countPairings(bool taken[]) {
  int firstFree = -1;

  for (int i = 0; i < n; i++) {
    if (!taken[i]) {
      firstFree = i;
      break;
    }
  }

  if (firstFree == -1) return 1;

  int ret = 0;

  for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
    if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
      taken[firstFree] = taken[pairWith] = true;
      ret += countPairings(taken);
      taken[firstFree] = taken[pairWith] = false;
    }
  }
  return ret;
}