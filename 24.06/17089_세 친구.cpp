// https://www.acmicpc.net/problem/17089
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, ans = 2e9 + 1;
vector<int> v[4001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = j + 1; k < v[i].size(); k++) {
				if (find(v[v[i][j]].begin(), v[v[i][j]].end(), v[i][k]) != v[v[i][j]].end()) {
					if (ans > v[i].size() + v[v[i][j]].size() + v[v[i][k]].size() - 6) ans = v[i].size() + v[v[i][j]].size() + v[v[i][k]].size() - 6;
				}
			}
		}
	}
	if (ans == 2e9 + 1) ans = -1;
	cout << ans << '\n';
}