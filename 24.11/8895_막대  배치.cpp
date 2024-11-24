// https://www.acmicpc.net/problem/8895
#include <iostream>
using namespace std;
long T, N, L, R, dp[21][21][21];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> T;
  dp[1][1][1] = 1;
  while (T--) {
    cin >> N >> L >> R;
    for (int i = 2; i <= N; i++)
      for (int l = 1; l <= L; l++)
        for (int r = 1; r <= R; r++)
          dp[i][l][r] = dp[i - 1][l][r] * (i - 2) + dp[i - 1][l - 1][r] + dp[i - 1][l][r - 1];
    cout << dp[N][L][R] << '\n';
  }
}