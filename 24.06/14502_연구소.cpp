// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int, int> > q;
int N, M, ans, cnt;
int map[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
	queue<pair<int, int> > qq = q;
	bool vis[8][8] = {0};
	int danger = 0;
	while (!qq.empty())	{
		auto cur = qq.front(); qq.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.second;
			int ny = dy[dir] + cur.first;
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[ny][nx] || vis[ny][nx]) continue;
			vis[ny][nx] = 1;
			qq.push({ny, nx});
			danger++;
		}
	}
	if (ans < cnt - danger - 3) ans = cnt - danger - 3;
}

void ft(int y, int x, int dep) {
	if (dep == 3) {
		bfs();
	} else {
		for (int i = y; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i == y && j <= x) continue;
				if (map[i][j] == 0) {
					map[i][j] = 1;
					ft(i, j, dep + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) cnt++;
			if (map[i][j] == 2) q.push({i, j});
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				ft(i, j, 1);
				map[i][j] = 0;
			}
		}
	}
	cout << ans << '\n';
}