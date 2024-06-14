// https://www.acmicpc.net/problem/11657
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
vector<tuple<int, int, int> > v;
long N, M, d[501], INF = 0xffffffff;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({a, b, c});
	}
	fill(d, d + 1 + N, INF);
	d[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int from, to, c; tie(from, to, c) = v[j];
			if (d[from] == INF) continue;
			if (d[to] > d[from] + c) {
				d[to] = d[from] + c;
				if (i == N) {
					cout << "-1\n";
					return 0;
				}
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (d[i] == INF) cout << "-1\n";
		else cout << d[i] << '\n';
	}
}