// https://www.acmicpc.net/problem/5546
#include <iostream>
using namespace std;
int arr[101], N, K, dp[101][3][2], MOD = 10000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    int d; cin >> d >> arr[d];
  }
  if (!arr[1] || arr[1] == 1) dp[1][0][0] = 1;
  if (!arr[1] || arr[1] == 2) dp[1][1][0] = 1;
  if (!arr[1] || arr[1] == 3) dp[1][2][0] = 1;
  for (int i = 2; i <= N; i++) {
    if (!arr[i] || arr[i] == 1) {
      dp[i][0][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][2][0] + dp[i - 1][2][1]) % MOD;
      dp[i][0][1] = dp[i - 1][0][0];
    }
    if (!arr[i] || arr[i] == 2) {
      dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][2][0] + dp[i - 1][2][1]) % MOD;
      dp[i][1][1] = dp[i - 1][1][0];
    }
    if (!arr[i] || arr[i] == 3) {
      dp[i][2][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][1][0] + dp[i - 1][1][1]) % MOD;
      dp[i][2][1] = dp[i - 1][2][0];
    }
  }
  cout << (dp[N][0][0] + dp[N][1][0] + dp[N][2][0] + dp[N][0][1] + dp[N][1][1] + dp[N][2][1]) % MOD << '\n';
}