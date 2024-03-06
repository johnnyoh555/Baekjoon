// https://www.acmicpc.net/problem/15990

#include <iostream>

using namespace std;

long arr[100001][3];

int t, n, mod = 1000000009;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[1][0] = 1;
	arr[2][1] = 1;
	arr[3][0] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;
	cin >> t;
	for (int j = 4; j <= 100000; j++) {
		arr[j][0] = (arr[j - 1][1] + arr[j - 1][2]) % mod;
		arr[j][1] = (arr[j - 2][0] + arr[j - 2][2]) % mod;
		arr[j][2] = (arr[j - 3][0] + arr[j - 3][1]) % mod;
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << (arr[n][0] + arr[n][1] + arr[n][2]) % mod << '\n';
	}
}