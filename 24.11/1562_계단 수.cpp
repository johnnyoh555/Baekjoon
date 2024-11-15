// https://www.acmicpc.net/problem/1562
#include <iostream>
using namespace std;
long dp[10][100][1 << 10], INF = 1e9, N, ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i < 10; i++) {
    if (i) dp[i][0][1 << i] = 1;
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 1 << 10; k++) {
        if (!dp[j][i][k]) continue;
        if (dp[j][i][k] >= INF) dp[j][i][k] %= INF;
        if (j) dp[j - 1][i + 1][k | 1 << j - 1] += dp[j][i][k];
        if (j < 9) dp[j + 1][i + 1][k | 1 << j + 1] += dp[j][i][k];
      }
    }
  }
  for (int i = 0; i < 10; i++) ans += dp[i][N - 1][(1 << 10) - 1];
  cout << ans % INF << '\n';
}