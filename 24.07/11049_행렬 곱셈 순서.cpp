// https://www.acmicpc.net/problem/11049
#include <iostream>
#include <cmath>
using namespace std;
long dp[501][501], arr[501][2], N, INF = 2e10;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1];
	for (int i = 1; i < N; i++) {
		for (int j = 1; j + i <= N; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[j][0] * arr[k][1] * arr[i + j][1]);
		}
	}
	cout << dp[1][N] << '\n';
}