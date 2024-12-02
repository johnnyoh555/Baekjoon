// https://www.acmicpc.net/problem/2616
#include <iostream>
#include <algorithm>
using namespace std;
int arr[50001], N, K, dp[4][50001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  cin >> K;
  for (int i = K; i <= N; i++) {
    for (int j = 1; j <= 3; j++) {
      if (i < j * K) continue;
      dp[j][i] = max(dp[j - 1][i - K] + arr[i] - arr[i - K], dp[j][i - 1]);
    }
  }
  cout << dp[3][N] << '\n';
}