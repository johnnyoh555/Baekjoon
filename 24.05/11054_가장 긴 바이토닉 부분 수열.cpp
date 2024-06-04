// https://www.acmicpc.net/problem/11054
#include <iostream>
#include <cmath>
using namespace std;
int dp[2][1000], N, arr[1000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		dp[0][i] = 1;
		dp[1][i] = 1;
		int mx = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) dp[0][i] = max(dp[0][i], dp[0][j] + 1);
			if (arr[j] > arr[i]) dp[1][i] = max(dp[1][i], max(dp[0][j] + 1, dp[1][j] + 1));
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (dp[0][i] > ans) ans = dp[0][i];
		if (dp[1][i] > ans) ans = dp[1][i];
	}
	cout << ans << '\n';
}