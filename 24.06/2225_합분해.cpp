// https://www.acmicpc.net/problem/2225
#include <iostream>
using namespace std;
long dp[201][201], N, K, mod = 1000000000;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i <= N; i++) dp[1][i] = 1;
	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) dp[i][j] += dp[i - 1][k];
			dp[i][j] %= mod;
		}
	}
	cout << dp[K][N] << '\n';
}