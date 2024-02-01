// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int	board[101][101];
int vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N, K;
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int start_x, start_y, end_x, end_y;

		cin >> start_y >> start_x >> end_y >> end_x;

		for (int j = start_y; j < end_y; j++) {
			for (int k = start_x; k < end_x; k++) {
				board[j][k] = 1;
			}
		}
	}

	vector<int> 	V;
	queue<pair<int, int> > Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j] || board[i][j])
				continue ;
			int cnt = 1;
			Q.push(make_pair(i, j));
			vis[i][j] = 1;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.second + dx[dir];
					int ny = cur.first + dy[dir];
					if (nx < 0 || ny < 0 || nx >= M || ny >= N)
						continue ;
					if (vis[ny][nx] || board[ny][nx])
						continue ;
					vis[ny][nx] = 1;
					Q.push(make_pair(ny, nx));
					cnt++;
				}
			}
			V.push_back(cnt);
		}
	}
	sort(V.begin(),V.end());
	cout << V.size() << '\n';
	for (int i = 0; i < V.size(); i++) {
		if (i)
			cout << ' ';
		cout << V[i];
	}
	cout << '\n';
}