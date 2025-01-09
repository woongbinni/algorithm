#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long sum = 0;
	for (int i = 1;i <= n;i++) {
		sum += i * (n / i);
	}
	cout << sum;
}