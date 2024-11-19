// https://www.acmicpc.net/problem/11066
#include <iostream>
#include <algorithm>
using namespace std;
int dp[2][501][501], N, T;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
      fill(dp[1][i], dp[1][i] + N + 1, 2e9);
    }
    for (int i = 1; i <= N; i++) {
      cin >> dp[0][i][i];
      dp[1][i][i] = 0;
    }
    for (int i = 1; i < N; i++) {
      for (int j = 1; j + i <= N; j++) {
        for (int k = 0; k < i; k++) {
          if (dp[1][j][j + i] <= dp[1][j][j + k] + dp[1][j + 1 + k][j + i] + dp[0][j][j + k] + dp[0][j + 1 + k][j + i]) continue;
          dp[1][j][j + i] = dp[1][j][j + k] + dp[1][j + 1 + k][j + i] + dp[0][j][j + k] + dp[0][j + 1 + k][j + i];
          dp[0][j][j + i] = dp[0][j][j + k] + dp[0][j + 1 + k][j + i];
        }
      }
    }
    cout << dp[1][1][N] << '\n';
  }
}