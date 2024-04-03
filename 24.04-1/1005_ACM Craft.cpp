// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int T, N, K, W, x, y;
int tm[1001];
int id[1001];
int d[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int mx = 0;
		vector<int> v[1001];
		queue<pair<int, int> > q;
		cin >> N >> K;
		for (int j = 1; j <= N; j++) cin >> tm[j];
		for (int j = 1; j <= K; j++) {
			cin >> x >> y;
			id[y]++; v[x].push_back(y);
		}
		cin >> W;
		for (int j = 1; j <= N; j++) if (!id[j]) {q.push({j, tm[j]}); d[j] = tm[j];}
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			if (cur.first == W) break;
			for (int nxt : v[cur.first]) {
				id[nxt]--;
				d[nxt] = max(d[nxt], cur.second + tm[nxt]);
				if (!id[nxt]) q.push({nxt, d[nxt]});
			}
		}
		cout << d[W] << '\n';
		memset(tm, 0, sizeof(tm));
		memset(d, 0, sizeof(d));
		memset(id, 0, sizeof(id));
	}
}