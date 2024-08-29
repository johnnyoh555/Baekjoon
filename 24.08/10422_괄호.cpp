// https://www.acmicpc.net/problem/10422
#include <iostream>
using namespace std;
long T, dp[5001], mx, L[100], mod = 1000000007;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  dp[2] = 1;
  dp[0] = 1;
  for (int i = 0; i < T; i++) {
    cin >> L[i];
    if (L[i] > mx) mx = L[i];
  }
  for (int i = 4; i <= mx; i += 2) {
    for (int j = 2; j <= i; j += 2) {
      dp[i] += dp[j - 2] * dp[i - j];
      dp[i] %= mod;
    }
  }
  for (int i = 0; i < T; i++)
    cout << dp[L[i]] << '\n';
}