// https://www.acmicpc.net/problem/5582
#include <iostream>
using namespace std;
string A, B;
int dp[4001][4001], ans;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {
      if (A[i] != B[j]) continue;
      dp[i + 1][j + 1] = dp[i][j] + 1;
      if (dp[i + 1][j + 1] > ans) ans = dp[i + 1][j + 1];
    }
  }
  cout << ans << '\n';
}