// https://www.acmicpc.net/problem/17845
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, a, b, dp[10001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> a >> b;
    for (int j = N; j >= b; j--)
      dp[j] = max(dp[j], dp[j - b] + a);
  }
  cout << dp[N] << '\n';
}