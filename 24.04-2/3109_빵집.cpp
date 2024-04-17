// https://www.acmicpc.net/problem/3109
#include <iostream>
using namespace std;
int R, C, ans;
string bd[10002];
bool vis[10002][502];

int dfs(int y, int x) {
	if (x == C - 1) return 1;
	if (y > 0 && !vis[y - 1][x + 1] && bd[y - 1][x + 1] == '.') {
		vis[y - 1][x + 1] = 1;
		if (dfs(y - 1, x + 1)) return 1;
	}
	if (!vis[y][x + 1] && bd[y][x + 1] == '.') {
		vis[y][x + 1] = 1;
		if (dfs(y, x + 1)) return 1;
	}
	if (y > 0 && !vis[y + 1][x + 1] && bd[y + 1][x + 1] == '.') {
		vis[y + 1][x + 1] = 1;
		if (dfs(y + 1, x + 1)) return 1;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) cin >> bd[i];
	for (int i = 1; i <= R; i++) {
		vis[i][0] = 1;
		ans += dfs(i, 0);
	}
	cout << ans << '\n';
}