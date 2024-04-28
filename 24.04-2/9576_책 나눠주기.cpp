// https://www.acmicpc.net/problem/9576
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, M, a, b;
bool vis[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<pair<int, int> > v;
		int cnt = 0;
		cin >> N >> M;
		bool vis[1001] = {0};
		for (int k = 0; k < M; k++) {cin >> a >> b; v.push_back({b, a});}
		sort(v.begin(), v.end());
		for (int k = 0; k < M; k++) {
			for (int j = v[k].second; j <= v[k].first; j++)
				if (!vis[j]) {vis[j] = 1; cnt++; break;}
		}
		cout << cnt << '\n';
	}
}