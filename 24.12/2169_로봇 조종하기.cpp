// https://www.acmicpc.net/problem/2169
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, board[1001][1001], dx[3] = {1, 0, -1}, dy[3] = {0, -1, 0}, INF = -1e9, dp[1001][1001][3];

int dfs(int y, int x, int dir) {
  if (dp[y][x][dir] != INF) return dp[y][x][dir];
  for (int i = 0; i < 3; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if ((i == 0 && dir == 2) || (i == 2 && dir == 0)) continue;
    if (nx <= 0 || nx > M || ny <= 0) continue;
    dp[y][x][dir] = max(dp[y][x][dir], dfs(ny, nx, i) + board[y][x]);
  }
  return dp[y][x][dir];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  fill(&dp[0][0][0], &dp[1000][1000][3], INF);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      cin >> board[i][j];
  for (int i = 0; i < 3; i ++)
    dp[1][1][i] = board[1][1];
  cout << dfs(N, M, 1) << '\n';
}
