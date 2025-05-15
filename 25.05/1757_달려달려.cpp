// https://www.acmicpc.net/problem/1757
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, x, dp[10002][502], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	fill(&dp[0][0], &dp[0][0] + 10002 * 502, -1);
	dp[1][0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		for (int j = 0; j <= M; j++) {
			if (dp[i][j] == -1) continue; 
			if (j <= M) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + x);
			}
			if (j == 0) {
				dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
			} else if (i + j <= N + 1) {
				dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
			}
		}
	}
	cout << dp[N + 1][0] << '\n';
}