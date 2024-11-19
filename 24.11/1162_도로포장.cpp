// https://www.acmicpc.net/problem/1162
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
long N, M, K, dp[21][10001], ans = 2e15;
vector<pair<long, long>> v[10001];
priority_queue<tuple<long, long, long>, vector<tuple<long, long, long>>, greater<tuple<long, long, long>>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	for (int i = 0; i <= K; i++) {
		fill(dp[i], dp[i] + 1 + N, 2e15);
	}
	dp[0][1] = 0;
	pq.push({0, 0, 1});
	while (!pq.empty()) {
		long c, s, idx; tie(c, s, idx) = pq.top(); pq.pop();
		if (dp[s][idx] != c) continue;
		for (auto nxt : v[idx]) {
			if (s != K) {
				bool flag = 0;
				for (int i = 0; i <= s + 1; i++) {
					if (dp[i][nxt.first] <= c) flag = 1;
				}
				if (!flag) {
					dp[s + 1][nxt.first] = c;
					pq.push({c, s + 1, nxt.first});
				}
			}
			if (dp[s][nxt.first] <= c + nxt.second) continue;
			dp[s][nxt.first] = c + nxt.second;
			pq.push({dp[s][nxt.first], s, nxt.first});
		}
	}
	for (int i = 0; i <= K; i++) {
		if (dp[i][N] < ans) ans = dp[i][N];
	}
	cout << ans << '\n';
}