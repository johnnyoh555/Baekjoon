// https://www.acmicpc.net/problem/7570
#include <iostream>
using namespace std;
int d[1000001], N, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int t; cin >> t;
		d[t] = d[t - 1] + 1;
		if (d[t] > a) a = d[t];
	}
	cout << N - a << '\n';
}