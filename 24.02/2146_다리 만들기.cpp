// https://www.acmicpc.net/problem/2146

#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

short vis[101][101];
short board[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	int a = 1;
	queue<pair<int, int> > Q;
	for (int i = 0; i < N; i++) {
		for (int j= 0; j < N; j++) {
			if (board[i][j] != 1) continue ;
			a++;
			board[i][j] =	a;
			Q.push({i, j});
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.second + dx[dir];
					int ny = cur.first + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (board[ny][nx] != 1) continue;
					board[ny][nx] = a;
					Q.push({ny, nx});
				}
			}
		}
	}
	fill(&vis[0][0], &vis[100][100], 10000);
	int min = 1000000000;
	for (int i = 0; i < N; i++) {
		for (int j= 0; j < N; j++) {
			queue<pair<short, short> > NQ;
			if (board[i][j] == 0) continue ;
			int f = board[i][j];
			vis[i][j] = 0;
			NQ.push({i, j});
			while (!NQ.empty()) {
				bool flag = 0;
				pair<short, short> cur = NQ.front();
				NQ.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.second + dx[dir];
					int ny = cur.first + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (board[ny][nx] == f) continue;
					if (vis[ny][nx] <= vis[cur.first][cur.second] + 1) continue;
					if (board[ny][nx]) {
						if (vis[cur.first][cur.second] < min)
							min = vis[cur.first][cur.second];
						flag = 1;
						break;
					}
					vis[ny][nx] = vis[cur.first][cur.second] + 1;
					NQ.push({ny, nx});
				}
				if (flag)
					break ;
			}
		}
	}
	cout << min << '\n';
}