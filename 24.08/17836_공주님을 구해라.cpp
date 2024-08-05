// https://www.acmicpc.net/problem/17836
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int board[101][101];
int N, M, T, x, y, vis[101][101], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, ans = 10001;
queue<pair<int, int> > q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> T;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      cin >> board[i][j]; 

  q.push({1, 1});
  vis[1][1] = 1;
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    if (board[cur.first][cur.second] == 2) {
      int tmp = N - cur.first + M - cur.second;
      if (vis[cur.first][cur.second] - 1 + tmp < ans) ans = vis[cur.first][cur.second] - 1 + tmp;
      continue;
    }
    if (cur.first == N && cur.second == M) {
      if (ans > vis[N][M] - 1) ans = vis[N][M] - 1;
      break;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.second + dx[dir];
      int ny = cur.first + dy[dir];
      if (nx <= 0 || ny <= 0 || nx > M || ny > N) continue;
      if (board[ny][nx] == 1 || vis[ny][nx]) continue;
      vis[ny][nx] = vis[cur.first][cur.second] + 1;
      q.push({ny, nx});
    }
  }
  if (ans > T) cout << "Fail\n";
  else cout << ans << '\n';
}