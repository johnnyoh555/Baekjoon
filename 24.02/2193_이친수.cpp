// https://www.acmicpc.net/problem/2193

#include <iostream>

using namespace std;

long long d[91][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	d[1][0] = 0;
	d[1][1] = 1;
	d[2][0] = 1;
	d[2][1] = 0;
	for (int i = 3; i <= N; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[N][0] + d[N][1] << '\n';
}
