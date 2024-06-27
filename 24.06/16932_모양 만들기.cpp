// https://www.acmicpc.net/problem/16932
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, M, map[1001][1001], vis[1001][1001], s[500001], nb, ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	int cnt = 1;
	q.push({y, x});
	vis[y][x] = nb;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.second + dx[dir];
			int ny = cur.first + dy[dir];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (!map[ny][nx] || vis[ny][nx]) continue;
			cnt++;
			vis[ny][nx] = nb;
			q.push({ny, nx});
		}
	}
	s[nb] = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !vis[i][j]) {
				nb++;
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j]) {
				int sum = 0;
				int tmp[4] = {0, 0, 0, 0};
				for (int dir = 0; dir < 4; dir++) {
					int nx = j + dx[dir];
					int ny = i + dy[dir];
					if (nx < 0 || ny < 0 || nx >= M || ny >= N || !map[ny][nx]) continue;
					if (vis[ny][nx] == tmp[0] || vis[ny][nx] == tmp[1] || vis[ny][nx] == tmp[2] || vis[ny][nx] == tmp[3]) continue;
					tmp[dir] = vis[ny][nx];
					sum += s[vis[ny][nx]];
				}
				if (sum > ans) {
					ans = sum;
				}
			}
		}
	}
	cout << ans + 1 << '\n';
}