// https://www.acmicpc.net/problem/6118

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v[20001];
vector<int> arr[20001];
bool	vis[20001];
int N, M, mx;

void	bfs() {
	queue<pair<int, int> > Q;
	Q.push({1, 0});
	vis[1] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		bool flag = 0;
		Q.pop();
		for (int i = 0; i < v[cur.first].size(); i++) {
			if (vis[v[cur.first][i]]) continue;
			flag = 1;
			vis[v[cur.first][i]] = 1;
			Q.push({v[cur.first][i], cur.second + 1});
		}
		if (!flag) {
			if (cur.second >= mx) {
				arr[cur.second].push_back(cur.first);
				mx = cur.second;
			}
		}
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
	bfs();
	sort(arr[mx].begin(), arr[mx].end());
	cout << arr[mx][0] << ' ' << mx << ' ' << arr[mx].size() << '\n';
}