// https://www.acmicpc.net/problem/2636
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, M, ans, cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
short map[100][100];
queue<pair<short, short> > cheeze;
queue<pair<short, short> > air;

void ft2() {
	int s = cheeze.size();
	while (s--) {
		bool flag = 0;
		auto cur = cheeze.front(); cheeze.pop();
		for (int dir = 0; dir < 4; dir++) {
			short nx = dx[dir] + cur.second;
			short ny = dy[dir] + cur.first;
			if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] != -1) continue;
			else {
				flag = 1;
				air.push(cur);
				break;
			}
		}
		if (!flag) cheeze.push(cur);
	}
}

void ft1() {
	bool vis[100][100] = {0};
	while (!air.empty()) {
		auto cur = air.front(); air.pop();
		map[cur.first][cur.second] = -1;
		vis[cur.first][cur.second] = 1;
		for (int dir = 0; dir < 4; dir++) {
			short nx = dx[dir] + cur.second;
			short ny = dy[dir] + cur.first;
			if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;
			if (vis[ny][nx] || map[ny][nx] != 0) continue;
			vis[ny][nx] = 1;
			air.push({ny, nx});
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) cheeze.push({i, j});
		}
	}
	air.push({0, 0});
	while (!cheeze.empty()) {
		ans = cheeze.size();
		ft1();
		ft2();
		cnt++;
	}
	cout << cnt << '\n' << ans << '\n';
}