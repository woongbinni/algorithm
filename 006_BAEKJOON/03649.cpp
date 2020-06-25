#include <cstdio>
#include <algorithm>
using namespace std;
 
int len;
int n;
int lego[1000001];
 
int bsearch(int num)
{
    int s = 0, e = n - 1;
    int m;
 
    while (s <= e) {
        m = (s + e) / 2;
 
        if (lego[m] < num)  s = m + 1;
        else                e = m - 1;
    }
 
    if (lego[e + 1] == num) return 1;
    else                    return 0;
}
 
void solve()
{
    for (int i = 0; i < n; i++) {
        if (lego[i] * 2 == len) {
            if (lego[i + 1] == lego[i]) {
                printf("yes %d %d\n", lego[i], len - lego[i]);
                return;
            }
        }
        else if (bsearch(len - lego[i])) {
            printf("yes %d %d\n", lego[i], len - lego[i]);
            return;
        }
    }
 
    printf("danger\n");
}
 
int main()
{
    while (scanf("%d", &len) != EOF) {
        len = len * 10000000;
 
        scanf("%d", &n);
 
        for (int i = 0; i < n; i++) {
            scanf("%d", &lego[i]);
        }
        sort(lego, lego + n);
 
        solve();
    }
 
    return 0;
}