// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int bd[501][501];
int vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > Q;
	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			bd[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (bd[i][j] == 0 || vis[i][j])
				continue;
			vis[i][j] = 1;
			Q.push(make_pair(i, j));
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
						continue;
					if (vis[nx][ny] || bd[nx][ny] != 1)
						continue;
					vis[nx][ny] = vis[cur.first][cur.second] + 1;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << vis[N - 1][M - 1] << '\n';
}