// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;
int N, L, R, ans;
int map[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	
	bool flag = 1;
	while (flag) {
		flag = 0;
		bool vis[50][50] = {0};
		queue<pair<int, int> > q;
		queue<pair<int, int> > qq;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (vis[i][j]) continue;
				int sum = 0;
				vis[i][j] = 1;
				q.push({i, j});
				qq.push({i, j});
				sum += map[i][j];
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = dx[dir] + cur.second;
						int ny = dy[dir] + cur.first;
						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						if (vis[ny][nx] || !(abs(map[cur.first][cur.second] - map[ny][nx]) >= L &&  abs(map[cur.first][cur.second] - map[ny][nx]) <= R)) continue;
						vis[ny][nx] = 1;
						q.push({ny, nx});
						qq.push({ny, nx});
						sum += map[ny][nx];
						flag = 1;
					}
				}
				sum /= qq.size();
				while (!qq.empty()) {
					map[qq.front().first][qq.front().second] = sum;
					qq.pop();
				}
			}
		}
		ans += flag;
	}
	cout << ans << '\n';
}