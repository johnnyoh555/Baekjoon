// https://www.acmicpc.net/problem/2342
#include <iostream>
#include <algorithm>
using namespace std;
int dp[5][5], ndp[5][5], ans;
const int INF = 2e9;

int ft(int from, int to) {
  if (from == 0) return 2;
  if (from == to) return 1;
  if ((from + to) % 2 == 0) return 4;
  return 3;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ans = INF;
  fill(&dp[0][0], &dp[4][5], INF);
  dp[0][0] = 0;
  while (true) {
    int tmp; cin >> tmp;
    if (!tmp) break;
    fill(&ndp[0][0], &ndp[4][5], INF);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (dp[i][j] == INF) continue;
        if (i != tmp)
          ndp[i][tmp] = min(ndp[i][tmp], dp[i][j] + ft(j, tmp));
        if (j != tmp)
          ndp[tmp][j] = min(ndp[tmp][j], dp[i][j] + ft(i, tmp));
      }
    }
    swap(dp, ndp);
  }
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      ans = min(ans, dp[i][j]);
  cout << ans << '\n';
}