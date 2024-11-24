// https://www.acmicpc.net/problem/11062
#include <iostream>
#include <algorithm>
using namespace std;
int N, T, dp[1001][1001], arr[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 1; i <= N; i++)
      cin >> arr[i];
    for (int i = 0; i < N; i++) {
      for (int j = 1; j + i <= N; j++) {
        if (N % 2 != i % 2) {
          dp[j][j + i] = max(dp[j + 1][j + i] + arr[j], dp[j][j + i - 1] + arr[j + i]);
        } else {
          dp[j][j + i] = min(dp[j + 1][j + i], dp[j][j + i - 1]);
        }
      }
    }
    cout << dp[1][N] << '\n';
  }
}