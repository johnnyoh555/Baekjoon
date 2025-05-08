// https://www.acmicpc.net/problem/17208
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, dp[301][301];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    for (int j = M; j >= a; j--)
      for (int k = K; k >= b; k--)
        dp[j][k] = max(dp[j - a][k - b] + 1, dp[j][k]);
  }
  cout << dp[M][K] << '\n';
}