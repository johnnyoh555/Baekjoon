// https://www.acmicpc.net/problem/8980
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
long N, C, M, t, ans;
vector<pair<pair<int, int>, int> > v;

bool cmp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
	if (a.first.first == b.first.first) return a.first.second < b.first.second;
	return a.first.first < b.first.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C >> M;
	vector<int>	vis(2001, C);
	for (int i = 0; i < M; i++) {
		int a, b ,c; cin >> a >> b >> c;
		v.push_back({{b, a}, c});
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		int mn = 2e9;
		for (int j = v[i].first.second; j < v[i].first.first; j++) mn = min(mn, vis[j]);
		int tmp = min(mn, v[i].second);
		for (int j = v[i].first.second; j < v[i].first.first; j++) vis[j] -= tmp;
		ans += tmp;
	}
	cout << ans << '\n';
}