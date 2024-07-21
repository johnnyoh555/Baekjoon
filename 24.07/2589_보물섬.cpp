// https://www.acmicpc.net/problem/2589
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, M, ans;
bool board[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  int vis[51][51] = {0};
  int mx = 0;
  vis[y][x] = 1;
  q.push({y, x});
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = dx[dir] + cur.second;
      int ny = dy[dir] + cur.first;
      if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
      if (vis[ny][nx] || !board[ny][nx]) continue;
      vis[ny][nx] = vis[cur.first][cur.second] + 1;
      if (vis[ny][nx] > mx) mx = vis[ny][nx];
      q.push({ny, nx});
    }
  }
  if (mx - 1 > ans) ans = mx - 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char tmp; cin >> tmp;
      if (tmp == 'L') board[i][j] = 1; 
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j]) bfs(i, j);
    }
  }
  cout << ans << '\n';
}