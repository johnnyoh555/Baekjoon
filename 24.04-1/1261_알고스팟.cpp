// https://www.acmicpc.net/problem/1261
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
bool b[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, x, y, c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		string tmp; cin >> tmp;
		for (int j = 1; j <= N; j++)
			b[i][j] = tmp[j - 1] - '0';
	}
	pq.push({0, 1, 1});
	vis[1][1] = 1;
	while (!pq.empty()) {
		tie(c, y, x) = pq.top(); pq.pop();
		if (y == M && x == N) {cout << c << '\n'; return 0;}
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (vis[ny][nx]) continue;
			vis[ny][nx] = 1;
			if (b[ny][nx]) pq.push({c + 1, ny, nx});
			else pq.push({c, ny, nx});
		}
	}
}