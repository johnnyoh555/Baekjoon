//  https://www.acmicpc.net/problem/3067
#include <iostream>
using namespace std;
int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int N, M, arr[20], dp[10001] = {};
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		cin >> M;
		dp[0] = 1;
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				if (!dp[i] || i + arr[j] > M) continue;
				else dp[i + arr[j]] += dp[i];
			}
		}
		cout << dp[M] << '\n';
	}
}