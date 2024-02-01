// https://www.acmicpc.net/problem/1926

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool vis[501][501];
int bd[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int max = 0;
	int cnt = 0;

	cin >> n >> m;
	queue<pair<int, int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> bd[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = 0;
			if (bd[i][j] == 1 && vis[i][j] == 0) {
				cnt++;
				q.push(make_pair(i, j));
				vis[i][j] = 1;
				tmp++;
			}
			while (!q.empty()) {
				pair<int,int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int ny = cur.first + dy[dir];
					int nx = cur.second + dx[dir];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n)
						continue ;
					if (vis[ny][nx] || bd[ny][nx] == 0)
						continue ;
					vis[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					tmp++;
				}
			}
			if (tmp > max)
				max = tmp;
		}
	}
	std::cout << cnt << '\n' << max << '\n';
}