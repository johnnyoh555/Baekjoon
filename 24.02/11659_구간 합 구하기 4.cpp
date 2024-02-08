// https://www.acmicpc.net/problem/11659

#include <iostream>

using namespace std;

int d[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1 ; i <= N; i++) {
		cin >> d[i];
		d[i] += d[i - 1];
	}
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << d[e] - d[s - 1] << '\n';
	}
}