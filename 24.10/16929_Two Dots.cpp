// https://www.acmicpc.net/problem/16929
#include <iostream>
using namespace std;
int N, M, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char board[50][50];
int vis[50][50], ans;

void dfs(int y, int x, int dep, char c) {
  vis[y][x] = dep;
  for (int dir = 0; dir < 4; dir++) {
    if (ans) return;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
    if (board[ny][nx] == c && vis[ny][nx] && vis[ny][nx] + 3 <= dep) {ans = 1; return;}
    if (board[ny][nx] != c || vis[ny][nx]) continue;
    dfs(ny, nx, dep + 1, c);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string tmp; cin >> tmp;
    for (int j = 0; j < M; j++) {
      board[i][j] = tmp[j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (vis[i][j]) continue;
      dfs(i, j, 1, board[i][j]);
      if (ans) {cout << "Yes\n"; return 0;}
    }
  } 
  cout << "No\n";
}