// https://www.acmicpc.net/problem/11058
#include <iostream>
#include <cmath>
using namespace std;
long N, dp[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (long i = 1; i <= N; i++) {
		long cnt = 2;
		long mx = max(i, dp[i - 1] + 1);
		for (int k = i - 3; k >= 1; k--) {
			mx = max(mx, dp[k] * cnt);
			cnt++;
		}
		dp[i] = mx;
	}
	cout << dp[N] << '\n';
}