// https://www.acmicpc.net/problem/17425
#include <iostream>
using namespace std;
long T, N, dp[1000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 1000000; i++) {
    for (int j = 1; j * i <= 1000000; j++)
        dp[i * j] += i;
      dp[i] += dp[i - 1];
  }
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    cout << dp[N] << '\n';
  }
}