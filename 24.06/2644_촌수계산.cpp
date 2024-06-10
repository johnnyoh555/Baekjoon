// https://www.acmicpc.net/problem/2644
#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y, ans = -1;
vector<int>  v[101];
int vis[101];

void ft2(int a, int dep) {
	if (vis[a] >= 0) {
		ans = dep + vis[a];
		return;
	}
	vis[a] = dep;
	if (v[a].size()) ft2(v[a][0], dep + 1);
}

void ft1(int a, int dep) {
	vis[a] = dep;
	if (v[a].size()) ft1(v[a][0], dep + 1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> y >> m;
	fill(vis, vis + 101, -1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[b].push_back(a);
	}
	ft1(x, 0);
	ft2(y, 0);
	cout << ans << '\n';
}