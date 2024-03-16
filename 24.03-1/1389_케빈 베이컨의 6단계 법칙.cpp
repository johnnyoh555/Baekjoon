// https://www.acmicpc.net/problem/1389

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[101];
bool vis[101];

int N, M, x, mx = 2e10 + 1;

void bfs(int idx) {
	queue<pair<int, int> > Q;
	int cnt = 0;
	Q.push({idx, 1});
	vis[idx] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < v[cur.first].size(); i++) {
			if (vis[v[cur.first][i]]) continue;
			vis[v[cur.first][i]] = 1;
			cnt += cur.second;
			Q.push({v[cur.first][i], cur.second + 1});
		}
	}
	if (cnt < mx) {
		x = idx;
		mx = cnt;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		memset(vis, 0, sizeof(vis));
		bfs(i);
	}
	cout << x << '\n';
}