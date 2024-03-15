//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> arr[1001];
bool vis[1001];
int N, M, V;
vector<int> d;
vector<int> b;
queue<int> Q;

void	dfs(int i) {
	d.push_back(i);
	vis[i] = 1;
	sort(arr[i].begin(), arr[i].end());
	for (int j = 0; j < arr[i].size(); j++) {
		if (vis[arr[i][j]]) continue;
		dfs(arr[i][j]);;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(V);
	memset(vis, 0, sizeof(vis));
	Q.push(V);
	while (!Q.empty()) {
		int cur = Q.front();
		if (!vis[cur]) b.push_back(cur);
		vis[cur] = 1;
		Q.pop();
		sort(arr[cur].begin(), arr[cur].end());
		for (int j = 0; j < arr[cur].size(); j++) {
			if (vis[arr[cur][j]]) continue;
			Q.push(arr[cur][j]);;
		}
	}
	for(int i = 0; i < d.size(); i++) cout << d[i] << ' ';
	cout << '\n';
	for(int i = 0; i < b.size(); i++) cout << b[i] << ' ';
	cout << '\n';
}