// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

char board[101][101];
bool vis[101][101];
bool vis2[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			board[i][j] = tmp[j];
		}
	}
	queue<pair<int, int> > Q;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j])
				continue ;
			cnt++;
			vis[i][j] = 1;
			Q.push({i , j});
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.second + dx[dir];
					int ny = cur.first + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue ;
					if (vis[ny][nx] || board[ny][nx] != board[cur.first][cur.second])
						continue ;
					vis[ny][nx] = 1;
					Q.push({ny, nx});
				}
			}
		}
	}
	cout << cnt << ' ';
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis2[i][j])
				continue ;
			cnt++;
			vis2[i][j] = 1;
			Q.push({i , j});
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.second + dx[dir];
					int ny = cur.first + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue ;
					if (vis2[ny][nx])
						continue ;
					if (board[ny][nx] == 'B' && board[cur.first][cur.second] != 'B')
						continue ;
					if (board[ny][nx] != 'B' && board[cur.first][cur.second] == 'B')
						continue ;
					vis2[ny][nx] = 1;
					Q.push({ny, nx});
				}
			}
		}
	}
	cout << cnt << '\n';
}