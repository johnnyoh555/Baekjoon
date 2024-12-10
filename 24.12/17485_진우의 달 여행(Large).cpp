// https://www.acmicpc.net/problem/17485
#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][1001], dp[1001][1001][3], N, M, ans = 2e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      cin >> d[i][j];
  fill(&dp[1][1][0], &dp[1000][1000][3], 2e9);
  for (int i = 0; i < N; i++)
    for (int j = 1; j <= M; j++)
      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++) {
          if (k == l || (j == 1 && l == 0) || (j == M && l == 2)) continue;
          dp[i + 1][j + l - 1][l] = min(dp[i + 1][j + l - 1][l], dp[i][j][k] + d[i + 1][j + l - 1]);
        }
  for (int i = 1; i <= M; i++)
    for (int j = 0; j < 3; j++)
      ans = min(ans, dp[N][i][j]);
  cout << ans << '\n';
}