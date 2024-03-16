// https://www.acmicpc.net/problem/5567

#include <iostream>
#include <vector>

using namespace std;

vector<int> v[501];
bool	vis[501];

int n, m, cnt;

void dfs(int idx, int s) {
	if (s == 2) return;
	for (int i = 0; i < v[idx].size(); i++) {
		vis[v[idx][i]] = 1;
		dfs(v[idx][i], s + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 2; i <= n; i++) 
		if (vis[i]) cnt++;
	cout << cnt << '\n';
}