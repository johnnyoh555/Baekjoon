// https://www.acmicpc.net/problem/1325

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[10001];
vector<int> arr[10001];
bool	vis[10001];

int N, M, mx;

void bfs(int idx) {
	queue<int> Q;
	Q.push(idx);
	int cnt = 1;
	vis[idx] = 1;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			if (vis[v[cur][i]]) continue;
			vis[v[cur][i]] = 1;
			cnt++;
			Q.push(v[cur][i]);
		}
	}
	if (cnt >= mx) {
		mx = cnt;
		arr[cnt].push_back(idx);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		memset(vis, 0, sizeof(vis));
		bfs(i);
	}
	sort(arr[mx].begin(), arr[mx].end());
	for (int i = 0; i < arr[mx].size(); i++) {
		cout << arr[mx][i] << ' '; 
	}
	cout << '\n';
}