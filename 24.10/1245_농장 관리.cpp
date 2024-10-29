// https://www.acmicpc.net/problem/1245
#include <iostream>
#include <queue>
using namespace std;
int N, M, ans, board[100][70], dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
bool vis[100][70];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> board[i][j];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (vis[i][j] || !board[i][j]) continue;
      queue<pair<int, int>> q;
      bool flag = 0;
      q.push({i, j});
      vis[i][j] = 1;
      while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 8; dir++) {
          int ny = cur.first + dy[dir];
          int nx = cur.second + dx[dir];
          if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
          if (board[ny][nx] > board[i][j]) flag = 1;
          if (vis[ny][nx] || board[ny][nx] != board[i][j]) continue;
          q.push({ny, nx});
          vis[ny][nx] = 1;
        }
      }
      if (!flag) ans++;
    }
  }
  cout << ans << '\n';
}