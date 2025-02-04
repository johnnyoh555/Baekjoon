// https://www.acmicpc.net/problem/22115
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, a, dp[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  fill(dp + 1, dp + 1 + K, 2e9);
  for (int i = 0; i < N; i++) {
    cin >> a;
    for (int j = K; j >= a; j--) {
      dp[j] = min(dp[j], dp[j - a] + 1);
    }
  }
  if (dp[K] == 2e9) dp[K] = -1;
  cout << dp[K] << '\n';
}