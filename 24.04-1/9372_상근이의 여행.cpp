// https://www.acmicpc.net/problem/9372

#include <iostream>
using namespace std;

int T, N, M, a, b;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) cin >> a >> b;
		cout << N - 1 << '\n';
	}
}