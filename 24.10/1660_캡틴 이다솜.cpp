// https://www.acmicpc.net/problem/1660
#include <iostream>
#include <algorithm>
using namespace std;
int N, dp[300001], a[121], b[121];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  fill(dp + 1, dp + 1 + N, 2e9);
  for (int i = 1; i <= 120; i++) {
    a[i] = a[i - 1] + i;
    b[i] = b[i - 1] + a[i];
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= 120; j++) {
      if (i - b[j] < 0) break;
      dp[i] = min(dp[i], dp[i - b[j]] + 1);
    }
  cout << dp[N] << '\n';
}