// https://www.acmicpc.net/problem/5972
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v[50001];
int d[50001];
int N, M, INF = 0x3f3f3f3f;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({c, b});
		v[b].push_back({c, a});
	}
	fill(d, d + 1 + N, INF);
	d[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({d[1], 1});
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : v[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({d[nxt.second], nxt.second});
		}
	}
	cout << d[N] << '\n';
}