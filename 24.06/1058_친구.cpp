// https://www.acmicpc.net/problem/1058
#include <iostream>
#include <algorithm>
using namespace std;
int N, ans, cnt;
char map[51][51];
bool vis[51];

void check(int x, int dep) {
	if (!vis[x]) {cnt++; vis[x] = 1;}
	if (dep == 2) return;
	for (int i = 1; i <= N; i++) {
		if (map[x][i] == 'N') continue;
		check(i, dep + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string tmp; cin >> tmp;
		for (int j = 1; j <= N; j++) {
			map[i][j] = tmp[j - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		fill(vis, vis + 51, 0);
		vis[i] = 1;
		cnt = 0;
		check(i, 0);
		if (cnt > ans) ans = cnt;
	}
	cout << ans << '\n';
}