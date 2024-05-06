// https://www.acmicpc.net/problem/2879
#include <iostream>
#include <cmath>
using namespace std;
int N, be[1001], diff[1001], dp[1001], tmp;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> be[i];
	for (int i = 0; i < N; i++) {cin >> tmp; diff[i] = tmp - be[i];}
	dp[0] = abs(diff[0]);
	for (int i = 1; i < N; i++) {
		if (diff[i] * diff[i - 1] > 0) dp[i] = dp[i - 1] + max(0, abs(diff[i]) - abs(diff[i - 1]));
		else dp[i] = dp[i - 1] + abs(diff[i]);
	}
	cout << dp[N - 1] << '\n';
}