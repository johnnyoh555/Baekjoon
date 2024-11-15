// https://www.acmicpc.net/problem/1727
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, boy[1001], girl[1001], dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 
	for (int i = 1; i <= n; i++) cin >> boy[i];
	for (int i = 1; i <= m; i++) cin >> girl[i];
	sort(boy + 1, boy + n + 1);
	sort(girl + 1, girl + 1 + m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) dp[i][j] = dp[i - 1][j - 1] + abs(boy[i] - girl[j]);
			else if (i > j) dp[i][j] = min(dp[i - 1][j - 1] + abs(boy[i] - girl[j]), dp[i - 1][j]);
			else dp[i][j] = min(dp[i - 1][j - 1] + abs(boy[i] - girl[j]), dp[i][j - 1]);
		}
	}
	cout << dp[n][m] << '\n';
}