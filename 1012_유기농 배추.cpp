// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int  main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int board[51][51] = {0, };
		int vis[51][51] = {0, };
		int M, N, K;
		cin >> M >> N >> K;

		int cnt = 0;

		queue<pair<int, int> > Q;

		for (int j = 0; j < K; j++) {
			int tmp_x, tmp_y;
			cin >> tmp_x >> tmp_y;
			board[tmp_y][tmp_x] = 1;
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (vis[j][k] || board[j][k] != 1)
					continue ;
				vis[j][k] = 1;
				cnt++;
				Q.push(make_pair(j, k));
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.second + dx[dir];
						int ny = cur.first + dy[dir];
						if (nx < 0 || ny < 0 || nx >= M || ny >= N)
							continue ;
						if (vis[ny][nx] || board[ny][nx] != 1)
							continue ;
						vis[ny][nx] = 1;
						Q.push(make_pair(ny, nx));
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}