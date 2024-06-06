// https://www.acmicpc.net/problem/17070
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, ans;
queue<tuple<int, int, int> > q;
bool board[17][17];
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	q.push({1, 2, 0});
	while (!q.empty()) {
		int y, x, c; tie(y, x, c) = q.front(); q.pop();
		if (y == N && x == N) {ans++; continue;}
		for (int dir = 0; dir < 3; dir++) {
			if (c == 0 && dir == 1) continue;
			if (c == 1 && dir == 0) continue;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx > N || ny > N) continue;
			if (board[ny][nx]) continue;
			if (dir == 2 && (board[ny - 1][nx] || board[ny][nx - 1])) continue;
			q.push({ny, nx, dir});
		}
	}
	cout << ans << '\n';
}