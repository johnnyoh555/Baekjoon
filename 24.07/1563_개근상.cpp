// https://www.acmicpc.net/problem/1563
#include <iostream>
using namespace std;
int N, dp[2][3][1001], ans, mod = 1000000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  dp[0][0][1] = 1;
  dp[0][1][1] = 1;
  for (int j = 2; j <= N; j++) {
      dp[0][0][j] = (dp[0][0][j - 1] + dp[0][1][j - 1] + dp[0][2][j - 1]) % mod;
      dp[0][1][j] = dp[0][0][j - 1];
      dp[0][2][j] = dp[0][1][j - 1];
  }
  dp[1][0][1] = 1;
  for (int j = 2; j <= N; j++) {
      dp[1][0][j] = (dp[0][0][j - 1] + dp[0][1][j - 1] + dp[0][2][j - 1] \
        + dp[1][0][j - 1] + dp[1][1][j - 1] + dp[1][2][j - 1]) % mod;
      dp[1][1][j] = dp[1][0][j - 1];
      dp[1][2][j] = dp[1][1][j - 1];
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ans += dp[i][j][N];
      if (ans >= mod) ans %= mod;
    }
  cout << ans << '\n';
  }
}