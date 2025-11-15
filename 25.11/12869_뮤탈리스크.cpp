// https://www.acmicpc.net/problem/12869
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int N, SCV[3], dp[61][61][61];
queue<tuple<int, int, int, int>> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> SCV[i];
  fill(&dp[0][0][0], &dp[60][60][61], 2e9);
  dp[SCV[0]][SCV[1]][SCV[2]] = 0;
  q.push({0, SCV[0], SCV[1], SCV[2]});
  while (!q.empty()) {
    auto [cnt, a, b, c] = q.front(); q.pop();
    int arr[3] = {1, 3, 9};
    cnt++;
    do {
      int na = clamp(a - arr[0], 0, 60);
      int nb = clamp(b - arr[1], 0, 60);
      int nc = clamp(c - arr[2], 0, 60);
      if (dp[na][nb][nc] <= cnt) continue;
      dp[na][nb][nc] = cnt;
      q.push({cnt, na, nb, nc});
    } while (next_permutation(arr, arr + 3));
  }
  cout << dp[0][0][0] << '\n';
}