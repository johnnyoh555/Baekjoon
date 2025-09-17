// https://www.acmicpc.net/problem/1106
#include <iostream>
#include <algorithm>
using namespace std;
int C, N, a, b, dp[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> C >> N;
  fill(dp, dp + 1001, 2e9);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    for (int j = 0; j < C; j++) {
      int tmp = j + b;
      if (tmp > C) tmp = C;
      dp[tmp] = min(dp[tmp], dp[j] + a);
    }
  }
  cout << dp[C] << '\n';
}