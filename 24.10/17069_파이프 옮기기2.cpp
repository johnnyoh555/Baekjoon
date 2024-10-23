// https://www.acmicpc.net/problem/17069
#include <iostream>
using namespace std;
long N, dp[3][33][33];
bool board[33][33];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      cin >> board[i][j];
  dp[0][1][2] = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      if (board[i][j]) continue;
      dp[0][i][j] += dp[0][i][j - 1] + dp[1][i][j - 1];
      dp[2][i][j] += dp[1][i - 1][j] + dp[2][i - 1][j];
      if (board[i - 1][j] || board[i][j - 1]) continue;
      dp[1][i][j] += dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
    }
  cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N] << '\n';
}