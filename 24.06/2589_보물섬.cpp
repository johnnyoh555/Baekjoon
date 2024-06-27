// https://www.acmicpc.net/problem/2589
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, ans;
bool vis[51][51];
int board[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string map[51];

int dfs(int y, int x) {
	int mx = 0;
	if (board[y][x] == -1) board[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (vis[ny][nx] || map[ny][nx] == 'W') continue;
		vis[ny][nx] = 1;
		int tmp = dfs(ny, nx);
		board[ny][nx] = max(tmp, mx);
		ans = max(ans, tmp + mx);
		mx = max(tmp, mx);
		vis[ny][nx] = 0;
	}
	return mx + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {cin >> map[i]; fill(board[i], board[i] + 51, -1);}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] >= 0 || map[i][j] != 'L') continue;
			vis[i][j] = 1;
			dfs(i, j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << board[i][j] + 1;
		cout << '\n';
	}
	
	cout << ans << '\n';
}