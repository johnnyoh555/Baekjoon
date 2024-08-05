// https://www.acmicpc.net/problem/13398
#include <iostream>
#include <cmath>
using namespace std;
int n, arr[100001], ans = -2e9 - 1, dp[2][100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
    dp[0][i] = max(arr[i] + dp[0][i - 1], arr[i]);
    if (ans < dp[0][i]) ans = dp[0][i];
    if (arr[i] >= 0) {
      dp[1][i] = arr[i] + dp[1][i - 1];
      if (ans < dp[1][i]) ans = dp[1][i];
    } else {
      dp[1][i] = max(dp[1][i - 1] + arr[i], dp[0][i - 1]); 
    }
  }
  cout << ans << '\n';
}