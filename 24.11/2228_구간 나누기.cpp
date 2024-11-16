// https://www.acmicpc.net/problem/2228
#include <iostream>
#include <cstring>
using namespace std;
int N, M, arr[101], dp[101][51], MIN = -987654321;

int ft(int n, int m) {
	if (m == 0) return 0;
	if (n <= 0) return MIN;
	if (dp[n][m] != -1) return dp[n][m];

	int sum = 0;
	dp[n][m] = ft(n - 1, m);
	for (int i = n; i > 0; i--) {
		sum += arr[i];
		int temp = ft(i - 2, m - 1) + sum;
		dp[n][m] = max(dp[n][m], temp);
	}
	return dp[n][m];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << ft(N, M) << '\n';
}