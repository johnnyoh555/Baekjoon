// https://www.acmicpc.net/problem/1309
#include <iostream>
using namespace std;
int N, dp[3][100001], MOD = 9901;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[0][1] = 1;
	dp[1][1] = 1;
	dp[2][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
	}
	cout << (dp[0][N] + dp[1][N] + dp[2][N]) % MOD << '\n';
}