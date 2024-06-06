// https://www.acmicpc.net/problem/1967
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int> > v[10001];
bool vis[10001];
int n, ans;

int ft(int x, int c) {
	int mx = 0;
	vis[x] = 1;
	for (auto nxt : v[x]) {
		if (vis[nxt.first]) continue;
		int tmp = ft(nxt.first, nxt.second);
		if (mx + tmp > ans) ans = mx + tmp;
		if (tmp > mx) mx = tmp;
	}
	return mx + c;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	ft(1, 0);
	cout << ans << '\n';
}