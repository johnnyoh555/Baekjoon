// https://www.acmicpc.net/problem/1937
#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, N, board[500][500], dp[500][500], ans;

int ft(int y, int x) {
  if (dp[y][x]) return dp[y][x];
  int ret = 0;
  for (int dir = 0; dir < 4; dir++) {
    int ny = dy[dir] + y;
    int nx = dx[dir] + x;
    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
    if (board[ny][nx] >= board[y][x]) continue;
    ret = max(ret, ft(ny, nx));
  }
  return dp[y][x] = ret + 1;
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> board[i][j];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      ans = max(ft(i, j), ans);
  cout << ans << '\n';
}