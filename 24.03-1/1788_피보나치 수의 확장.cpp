// https://www.acmicpc.net/problem/1788

#include <iostream>
#include <cmath>

using namespace std;

long arr[1000001];

int n, mod = 1000000000;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[1] = 1;
	cin >> n;
	if (n < 0) {
		for (int i = 2; i <= abs(n); i++) {
			arr[i] = (arr[i - 2] - arr[i - 1]) % mod;
		}
	} else {
		for (int i = 2; i <= n; i++) {
			arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
		}
	}
	if (arr[abs(n)] > 0) cout << "1\n";
	else if (arr[abs(n)] == 0) cout << "0\n";
	else cout << "-1\n";
	cout << abs(arr[abs(n)]) << '\n'; 
}