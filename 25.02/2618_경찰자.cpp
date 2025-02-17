// https://www.acmicpc.net/problem/2618
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, W, arr[2][1001];
int dp[1001][1001], store[1001][1001];

int dis(int y, int x, int idx) {
  int ny = arr[0][idx];
  int nx = arr[1][idx];
  return abs(ny - y) + abs(nx - x);
}

int dfs(int p1, int p2) {
  if (p1 == W || p2 == W) return 0;
  int tmp1, tmp2, m = max(p1, p2) + 1;

  if (store[p1][p2] != -1) {
    return store[p1][p2];
  }

  if (p1) {
    tmp1 = dfs(m, p2) + dis(arr[0][p1], arr[1][p1], m);
  } else {
    tmp1 = dfs(m, p2) + dis(1, 1, m);
  }
  if (p2) {
    tmp2 = dfs(p1, m) + dis(arr[0][p2], arr[1][p2], m);
  } else {
    tmp2 = dfs(p1, m) + dis(N, N, m);
  }
  if (tmp1 < tmp2) {
    store[p1][p2] = tmp1;
    dp[p1][p2] = 1;
    return tmp1;
  } else {
    store[p1][p2] = tmp2;
    dp[p1][p2] = 2;
    return tmp2;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> W;
  for (int i = 1; i <= W; i++) {
    cin >> arr[0][i] >> arr[1][i];
  }
  fill(&dp[0][0], &dp[1000][1001], -1);
  fill(&store[0][0], &store[1000][1001], -1);
  cout << dfs(0, 0) << '\n';
  int y = 0, x = 0;
  for (int i = 0; i < W; i++) {
    cout << dp[y][x] << '\n';
    if (dp[y][x] == 1) y = i + 1;
    else x = i + 1;
  }
}