// https://www.acmicpc.net/problem/2638

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int> > cheeze;
queue<pair<int, int> > air;

int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, t;

void checkCheeze() {
	size_t size = cheeze.size();
	for (int i = 0; i < size; i++) {
		auto cur = cheeze.front();
		cheeze.pop();
		int cnt = 0;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.second + dx[dir];
			int ny = cur.first + dy[dir];
			if (board[ny][nx] == -1) cnt++;
		}
		if (cnt < 2) cheeze.push(cur);
		else {
			board[cur.first][cur.second] = 0;
			air.push(cur);
		}
	}
}

void checkAir() {
	while (!air.empty()) {
		auto cur = air.front();
		air.pop();
		if (board[cur.first][cur.second] == -1) continue ;
		board[cur.first][cur.second] = -1;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.second + dx[dir];
			int ny = cur.first + dy[dir];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue ;
			if (board[ny][nx] != 0) continue ;
			air.push({ny, nx});
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j]) cheeze.push({i, j});
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) air.push({i, j});
		}
	}
	while (!cheeze.empty()) {
		checkAir();
		checkCheeze();
		t++;
	}
	cout << t << '\n';
}