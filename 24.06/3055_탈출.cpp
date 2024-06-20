// https://www.acmicpc.net/problem/3055
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
int R, C, x, y, ans = -1;
char map[51][51];
int board[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > water;

void ft2() {
	bool vis[51][51] = {0};
	queue<tuple<int, int, int> > q;
	q.push({y, x, 1});
	vis[y][x] = 1;
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front(); q.pop();
		if (map[a][b] == 'D') {
			cout << c - 1 << '\n';
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = b + dx[dir];
			int ny = a + dy[dir];
			if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
			if ((board[ny][nx] && board[ny][nx] <= c + 1) || map[ny][nx] == 'X' || vis[ny][nx]) continue;
			vis[ny][nx] = 1;
			q.push({ny, nx, c + 1});
		}
	}
	cout << "KAKTUS\n";
}

void ft1() {
	while (!water.empty()) {
		auto cur = water.front(); water.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.second + dx[dir];
			int ny = cur.first + dy[dir];
			if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
			if (board[ny][nx] || map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;
			board[ny][nx] = board[cur.first][cur.second] + 1;
			water.push({ny, nx});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[j];
			if (map[i][j] == 'S')	{y = i; x = j;}
			if (map[i][j] == '*') {water.push({i, j}); board[i][j] = 1;}
		}
	}
	ft1();
	ft2();
}