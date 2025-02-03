// https://www.acmicpc.net/problem/21772
#include <iostream>
using namespace std;
int R, C, T, Y, X, board[100][100], vis[100][100], ans, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int y, int x, int t, int c) {
  int tmp = vis[y][x];
  if (board[y][x] == 'S' && vis[y][x] == 0) c++;
  vis[y][x] = c + 1;
  if (t == T) {
    if (c > ans) ans = c;
  } else {
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
      if (board[ny][nx] == '#' || vis[ny][nx] > c) continue;
      dfs(ny, nx, t + 1, c);
    }
  }
  vis[y][x] = tmp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C >> T;
  for (int i = 0; i < R; i++) {
    string tmp; cin >> tmp;
    for (int j = 0; j < C; j++) {
      board[i][j] = tmp[j];
      if (tmp[j] == 'G') {
        Y = i; X = j;
      }
    }
  }
  dfs(Y, X, 0, 0);
  cout << ans << '\n';
}
