// https://www.acmicpc.net/problem/2573

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[301][301];
int vis[301][301];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int time = 0;
	while (true) {
		int	cnt = 0;
		bool vis[301][301] = {0, };
		queue<pair<int, int> > Q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (vis[i][j] || !board[i][j])
					continue ;
				vis[i][j] = 1;
				cnt++;
				Q.push({i, j});
				while(!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.second + dx[dir];
						int ny = cur.first + dy[dir];
						if (nx < 0 || ny < 0 || nx >= M || ny >= N)
							continue ;
						if (vis[ny][nx])
							continue ;
						if (!vis[ny][nx] && !board[ny][nx]) {
							if (board[cur.first][cur.second])
								board[cur.first][cur.second]--;
						}
						else {
							vis[ny][nx] = 1;
							Q.push({ny, nx});							
						}
					}	
				}
			}
		}
		if (cnt == 0) {
			cout << "0\n";
			return 0;
		}
		if (cnt >= 2) {
			cout << time << '\n';
			return 0;
		}
		time++;
	}
}