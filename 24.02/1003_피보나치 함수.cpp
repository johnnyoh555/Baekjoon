// https://www.acmicpc.net/problem/1003

#include <iostream>

using namespace std;

int d[41][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	d[0][0] = 1;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= 40; i ++) {
		d[i][0] = d[i - 1][0] + d[i - 2][0];
		d[i][1] = d[i - 1][1] + d[i - 2][1];
	}
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << d[N][0] << " " << d[N][1] << '\n';
	}
}
