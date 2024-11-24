// https://www.acmicpc.net/problem/1328
#include <iostream>
using namespace std;
long N, L, R, dp[101][101][101], mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> L >> R;
  dp[1][1][1] = 1;
  for (int idx = 2; idx <= N; idx++)
    for (int ll = 1; ll <= idx; ll++)
      for (int rr = 1; rr <= idx; rr++)
        dp[idx][ll][rr] = (dp[idx - 1][ll][rr] * (idx - 2) + dp[idx - 1][ll - 1][rr] + dp[idx - 1][ll][rr - 1]) % mod;
  cout << dp[N][L][R] << '\n';
}
