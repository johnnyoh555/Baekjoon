// https://www.acmicpc.net/problem/9095

#include <iostream>

using namespace std;


int main (void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int d[15] = {0, };
		int n;
		cin >> n;
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		for (int j = 4; j <= n; j++) {
			d[j] = d[j - 1] + d[j - 2] + d[j - 3];
		}
		cout << d[n] << '\n';
	}
}
