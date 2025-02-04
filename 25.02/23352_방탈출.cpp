// https://www.acmicpc.net/problem/23352
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M, board[50][50], cnt, ans, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
  queue<tuple<int, int, int>> q;
  bool vis[50][50] = {};
  vis[y][x] = 1;
  q.push({y, x, 1});
  while (!q.empty()) {
    int a, b, c;
    tie(a, b, c) = q.front(); q.pop();
    if ((c > cnt || (c == cnt && board[a][b] + board[y][x] > ans))) {
      ans = board[a][b] + board[y][x];
      cnt = c;
    }
    for (int dir = 0; dir < 4; dir++) {
      int ny = a + dy[dir];
      int nx = b + dx[dir];
      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
      if (board[ny][nx] == 0 || vis[ny][nx]) continue;
      vis[ny][nx] = 1;
      q.push({ny, nx, c + 1});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> board[i][j];
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 0) continue;
      bfs(i, j);
    }
  }
  cout << ans << '\n';
}