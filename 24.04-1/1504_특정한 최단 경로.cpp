// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
vector<pair<int, int> > v[801];
int N, E, a, b, c, v1, v2, m, f1, f2, s1, s2;
const int INF = 0x3f3f3f3f;

pair<int, int> dj(int from, int to, int to2) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	int d[801];

	fill(d, d + 1 + N, INF);
	d[from] = 0;
	pq.push({d[from], from});
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (pair<int, int> nxt : v[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({d[nxt.second], nxt.second});
		}
	}
	return {d[to], d[to2]};
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({c, b});
		v[b].push_back({c, a});
	}
	cin >> v1 >> v2;
	m = dj(v1, v2, 0).first;
	tie(f1, f2) = dj(1, v1, v2);
	tie(s1, s2) = dj(N, v1, v2);
	if (m == INF || f1 == INF || f2 == INF || s1 == INF || s2 == INF) cout << "-1\n";
	else if (f1 + s2 > f2 + s1) cout << f2 + s1 + m << '\n';
	else cout << f1 + s2 + m << '\n';
}