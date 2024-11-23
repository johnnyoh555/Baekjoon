// https://www.acmicpc.net/problem/2229
#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1001], dp[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 1; i <= N; i++) {
    int mx = arr[i], mn = arr[i];
    for (int j = i - 1; j >= 0; j--) {
      dp[i] = max(dp[i], dp[j] + abs(mx - mn));
      mx = max(mx, arr[j]);
      mn = min(mn, arr[j]);
    }
  }
  cout << dp[N] << '\n';
}