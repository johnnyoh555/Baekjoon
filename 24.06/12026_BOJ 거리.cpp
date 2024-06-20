// https://www.acmicpc.net/problem/12026
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
string str;
queue<pair<int, int> > q;
int vis[1001], N, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> str;
	fill(vis, vis + 1001, INF);
	vis[0] = 0;
	q.push({0, 0});
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.second != vis[cur.first]) continue;
		char c;
		if (str[cur.first] == 'B') c = 'O';
		if (str[cur.first] == 'O') c = 'J';
		if (str[cur.first] == 'J') c = 'B';
		for (int i = cur.first + 1; i < N; i++) {
			if (str[i] != c) continue;
			if (cur.second + pow(i - cur.first, 2) >= vis[i]) continue;
			vis[i] = cur.second + pow(i - cur.first, 2);
			q.push({i, vis[i]});
		}
	}
	if (vis[N - 1] == INF) vis[N - 1] = -1;
	cout << vis[N - 1] << '\n';
}

// #include <iostream>
// #include <cmath>
// using namespace std;
// int dp[1001], N, INF = 0x3f3f3f3f;
// string str;
// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
	
// 	cin >> N >> str;
// 	fill(dp, dp + 1001, INF);
// 	dp[0] = 0;
// 	for (int i = 0; i < N; i++) {
// 		if (dp[i] == INF) continue;
// 		char c;
// 		if (str[i] == 'B') c = 'O';
// 		if (str[i] == 'O') c = 'J';
// 		if (str[i] == 'J') c = 'B';
// 		for (int j = i + 1; j < N; j++) {
// 			if (str[j] != c) continue;
// 			if (dp[i] + pow(j - i, 2) >= dp[j]) continue;
// 			dp[j] = dp[i] + pow(j - i, 2);			
// 		}
// 	}
// 	if (dp[N - 1] == INF) dp[N - 1] = -1;
// 	cout << dp[N - 1] << '\n';
// }