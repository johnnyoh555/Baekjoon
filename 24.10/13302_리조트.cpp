// https://www.acmicpc.net/problem/13302
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, dp[41][110], INF = 2e9 + 1, ans = 2e9;
bool arr[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int tmp; cin >> tmp;
    arr[tmp] = 1;
  }
  for (int i = 0; i < 41; i++) fill(dp[i], dp[i] + 102, INF);
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 39; j++) {
      if (dp[j][i] == INF) continue;
      if (arr[i + 1]) dp[j][i + 1] = min(dp[j][i], dp[j][i + 1]);
      else {
        if (j >= 3) dp[j - 3][i + 1] = min(dp[j][i], dp[j - 3][i + 1]);
        dp[j][i + 1] = min(dp[j][i] + 10, dp[j][i + 1]);
      }
      dp[j + 1][i + 3] = min(dp[j][i] + 25, dp[j + 1][i + 3]);
      dp[j + 2][i + 5] = min(dp[j][i] + 37, dp[j + 2][i + 5]);
    }
  }
  for (int i = 0; i < 41; i++) if (ans > dp[i][N]) ans = dp[i][N];
  cout << ans * 1000 << '\n'; 
}