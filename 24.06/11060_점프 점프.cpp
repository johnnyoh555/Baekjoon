// https://www.acmicpc.net/problem/11060
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, arr[1001], dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	fill(dp, dp + 1001, 2e9);
	for (int i = 1; i <= N; i++) cin >> arr[i];
	dp[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j > N) break;
			dp[i + j] = min(dp[i] + 1, dp[i + j]);
		}
	}
	if (dp[N] == 2e9) dp[N] = -1;
	cout << dp[N] << '\n';
}