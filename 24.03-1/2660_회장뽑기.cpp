// https://www.acmicpc.net/problem/2660

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int>	v[51];
vector<int> r[51];
bool	vis[51];
int N, mn = 51;

void bfs(int idx) {
	queue<pair<int, int> > Q;
	vis[idx] = 1;
	Q.push({idx, 0});
	int cnt = 0;
	while (!Q.empty()) {
		pair<int, int>	cur = Q.front();
		Q.pop();
		if (cur.second > cnt) cnt = cur.second;
		for (int i = 0; i < v[cur.first].size(); i++) {
			if (vis[v[cur.first][i]]) continue;
			vis[v[cur.first][i]] = 1;
			Q.push({v[cur.first][i], cur.second + 1});
		}
	}
	if (cnt <= mn) {
		mn = cnt;
		r[cnt].push_back(idx);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		memset(vis, 0, sizeof(vis));
		bfs(i);
	}
	sort(r[mn].begin(), r[mn].end());
	cout << mn << ' ' << r[mn].size() << '\n';
	for (int i = 0; i < r[mn].size(); i++) {
		cout << r[mn][i] << ' ';
	}
	cout << '\n';
}