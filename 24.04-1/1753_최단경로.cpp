// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
int V, E, K, u, v, w;
int d[20001];
vector<pair<int, int> > arr[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		arr[u].push_back({w, v});
	}
	fill(d, d + V + 1, INF);
	d[K] = 0;
	pq.push({d[K], K});
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (pair<int, int> nxt : arr[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({d[nxt.second], nxt.second});
		}
	}
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}
}