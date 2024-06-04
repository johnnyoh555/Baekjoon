// https://www.acmicpc.net/problem/1987
#include <iostream>
using namespace std;
int R, C, ans;
char map[20][20];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool d[26];

void dfs(int y, int x, int dep) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = dx[dir] + x;
		int ny = dy[dir] + y;
		if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
		if (d[map[ny][nx] - 'A'] == 1) continue;
		d[map[ny][nx] - 'A'] = 1;
		dfs(ny, nx, dep + 1);
		d[map[ny][nx] - 'A'] = 0;
	}
	if (dep > ans) ans = dep;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < C; j++)
			map[i][j] = tmp[j];
	}
	d[map[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ans << '\n';
}