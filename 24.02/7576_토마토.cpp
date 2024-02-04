// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[1001][1001];
bool vis[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int M, N;

	queue<pair<int, int> > Q;
	cin >> M >> N;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < M; k++) {
			cin >> board[j][k];
			if (board[j][k] == 1)
				Q.push(make_pair(j, k));
		}
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();			
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.second + dx[dir];
			int ny = cur.first + dy[dir];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;
			if (vis[ny][nx] || board[ny][nx] != 0)
				continue;
			vis[ny][nx] = 1;
			board[ny][nx] = board[cur.first][cur.second] + 1;
			Q.push(make_pair(ny, nx));
		}
	}
	
	int max = 0;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < M; k++) {
			if (board[j][k] == 0) {
				cout << "-1\n";
				return 0;
			}
			if (board[j][k] > max)
				max = board[j][k];
		}
	}
	if (max == 0)
		cout << "-1\n";
	else
		cout << max - 1 << '\n';
}