/********************************************************************************
## 문제
최대 2 칸 까지 오를 수 있을 때 오르는 방법의 가짓수를 생각해 보자.
아래 그림은 n 이 4 인 경우의 예 이다.

1 - 2 - 3 - 4
1 - 2 - 4
1 - 3 - 4
2 - 3 - 4
2 - 4
총 5가지 경우가 존재한다.

그렇다면 계단의 수가 n개일 때는 경우의 수가 몇가지 존재할까? 답이 커질 수 있으므로 답을 1,000,000,007로 나눈 나머지를 출력한다.

입력
입력의 첫 줄은 계단의 갯수 (1 <= N <= 1,000,000,000)이 주어진다.

출력
계단 N개를 오를 수 있는 경우의 수를 10억 7로 나눈 나머지를 출력한다.

힌트
예제 입력
4
예제 출력
5
********************************************************************************/


#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long> > matrix;
const long long mod = 1000000007LL;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}
int main() {
    long long n;

    cin >> n;

    if (n <= 1) {
        cout << n << '\n';
        return 0;
    }
    n = n+1;

    matrix ans = {{1, 0}, {0, 1}};
    matrix a = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }

    cout << ans[0][1] << '\n';

    return 0;
}