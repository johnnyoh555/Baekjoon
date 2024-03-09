// https://www.acmicpc.net/problem/2482

#include <iostream>

using namespace std;

int d[1001][1001];
int N, K, sum, mod = 1000000003;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
	 d[i][0] = 1;
	 d[i][1] = i;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			d[i][j] = (d[i - 2][j - 1] + d[i - 1][j]) % mod;
		}
	}
	cout << (d[N - 1][K] + d[N - 3][K - 1]) % mod << '\n';
}

