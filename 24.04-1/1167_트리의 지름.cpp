// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int> > v[100001];
int N, a, b, c, ans;

int dfs(int x, int f) {
	int mx = 0;
	int d = 0;
	int ret;
	for (pair<int, int> nxt : v[x]) {
		if (nxt.first == f) {d = nxt.second; continue;}
		ret = dfs(nxt.first, x);
		ans = max(ans, ret + mx);
		mx = max(mx, ret);
	}
	return mx + d;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		while (true) {
			cin >> b; if (b == -1) break;
			cin >> c; v[a].push_back({b, c});
		}
	}
	dfs(1, 0);
	cout << ans << '\n';
}