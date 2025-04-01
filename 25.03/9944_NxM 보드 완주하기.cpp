// https://www.acmicpc.net/problem/9944
#include <iostream>
#include <cstring>
using namespace std;
int board[30][30], N, M, sum, ans = 2e9, c, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[30][30];

void dfs(int y, int x, int s, int dep) {
  if (s == sum) {
    if (dep < ans) ans = dep;
    return;
  }
  for (int dir = 0; dir < 4; dir++) {
    int nx = x;
    int ny = y;
    int ss = s;
    while (true) {
      int nnx = nx + dx[dir];
      int nny = ny + dy[dir];
      if (nnx >= M || nny >= N || nnx < 0 || nny < 0) break;;
      if (board[nny][nnx] == '*' || vis[nny][nnx]) break;
      nx = nnx;
      ny = nny;
      vis[ny][nx] = 1;
      ss++;
    }
    if (ss == s) continue;
    dfs(ny, nx, ss, dep + 1);
    while (nx != x || ny != y) {
      vis[ny][nx] = 0;
      nx -= dx[dir];
      ny -= dy[dir];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> N) {
    cin >> M;
    c++;
    ans = 2e9;
    sum = 0;
    for (int i = 0; i < N; i++) {
      string tmp; cin >> tmp;
      for (int j = 0; j < M; j++) {
        board[i][j] = tmp[j];
        if (tmp[j] == '.') sum++;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] == '*') continue;
        memset(vis, 0, sizeof(vis));
        vis[i][j] = 1;
        dfs(i, j, 1, 0);
        vis[i][j] = 0;
      }
    }
    if (ans == 2e9) ans = -1;
    cout << "Case " << c << ": " << ans << '\n';
  }
}