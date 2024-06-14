// https://www.acmicpc.net/problem/16948
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, r1, c1, r2, c2;
int dx[6] = {-1, 1, -2, 2, -1, 1};
int dy[6] = {-2, -2, 0, 0, 2, 2};
int vis[201][201];
queue<pair<int, int> > q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r1 >> c1 >> r2 >> c2;
	q.push({r1, c1});
	vis[r1][c1] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		if (cur.second == c2 && cur.first == r2) break;
		for (int i = 0; i < 6; i++) {
			int nx = cur.second + dx[i];
			int ny = cur.first + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (vis[ny][nx] != 0) continue;
			vis[ny][nx] = vis[cur.first][cur.second] + 1;
			q.push({ny, nx});
		}
	}
	cout << vis[r2][c2] - 1 << '\n';
}