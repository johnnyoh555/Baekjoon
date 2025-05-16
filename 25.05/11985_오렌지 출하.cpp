// https://www.acmicpc.net/problem/11985
#include <iostream>
#include <algorithm>
using namespace std;
long N, M, K, dp[20001], arr[20001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    dp[i] = K * i;
  }
  for (int i = 0; i < N; i++) {
    long mx = arr[i + 1], mn = arr[i + 1];
    for (int j = 1; j <= M; j++) {
      if (i + j > N) break;
      mx = max(mx, arr[i + j]);
      mn = min(mn, arr[i + j]);
      dp[i + j] = min(dp[i + j], dp[i] + K + j * (mx - mn));
    }
  }
  cout << dp[N] << '\n';
}