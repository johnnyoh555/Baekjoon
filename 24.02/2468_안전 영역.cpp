// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	queue<pair<int, int> > Q;
	int max = 0;
	for (int i = 0; i <= 100; i++) {
		bool vis[101][101] = {0, };
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (vis[j][k] || board[j][k] <= i)
					continue ;
				vis[j][k] = 1;
				cnt++;
				Q.push({j, k});
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.second + dx[dir];
						int ny = cur.first + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue ;
						if (vis[ny][nx] || board[ny][nx] <= i)
							continue ;
						vis[ny][nx] = 1;
						Q.push({ny, nx});
					}
				}
			}
		}
		if (cnt >= max)
			max = cnt;
	}
	cout << max << '\n';
}