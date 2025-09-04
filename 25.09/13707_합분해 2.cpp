// https://www.acmicpc.net/problem/13707
#include <iostream>
using namespace std;
int N, K, dp[5001] = {};
const int MOD = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> K;
  dp[0] = 1;
  for (int i = 1; i <= K; i++)
    for (int j = 1; j <= N; j++) {
      dp[j] += dp[j - 1];
      if (dp[j] >= MOD) dp[j] %= MOD;
    }
  cout << dp[N] << '\n';
}