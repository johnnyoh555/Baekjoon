// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<pair<int, int> > v[1001];
int d[1001];
int n, m, st, en;
const int INF = 0x3f3f3f3f;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({c, b});
	}
	cin >> st >> en;
	fill(d, d + 1 + n, INF);
	d[st] = 0;
	pq.push({d[st], st});
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (pair<int, int> nxt : v[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({d[nxt.second], nxt.second});
		}
	}
	cout << d[en] << '\n';
}
