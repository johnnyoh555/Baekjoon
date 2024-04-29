// https://www.acmicpc.net/problem/1493
#include <iostream>
#include <cmath>
using namespace std;
int x, y, z, n, a, cnt, v[21], p[21];

void	dfs(int l, int w, int h) {
	if (cnt == -1 || !l || !w || !h) return;
	for (int i = 20; i >= 0; i--) {
		if (p[i] <= l && p[i] <= w && p[i] <= h && v[i]) {
			v[i]--; cnt++;
			dfs(l - p[i], p[i], p[i]);
			dfs(l, w - p[i], p[i]);
			dfs(l, w, h - p[i]);
			return;
		}
	}
	cnt = -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y >> z >> n;
	for (int i = 0; i <= 20; i++) p[i] = pow(2, i);
	for (int i = 0; i < n; i++) cin >> a >> v[a];
	dfs(x, y, z);
	cout << cnt << '\n';
}