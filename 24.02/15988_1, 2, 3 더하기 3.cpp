// https://www.acmicpc.net/problem/15988

#include <iostream>

using namespace std;

long d[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;
	}
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}