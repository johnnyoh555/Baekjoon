// https://www.acmicpc.net/problem/14466
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int ans, N, K, R, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, arr[100][2];
bool board[101][101][4], d[101][101];

void ft(int y, int x) {
  bool vis[101][101] = {};
  queue<pair<int, int>> q;
  int cnt = 0;
  vis[y][x] = 1;
  q.push({y, x});
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      if (board[cur.first][cur.second][dir]) continue;
      int nx = cur.second + dx[dir];
      int ny = cur.first + dy[dir];
      if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
      if (vis[ny][nx]) continue;
      vis[ny][nx] = 1;
      if (d[ny][nx] == 1) cnt++;
      q.push({ny, nx});
    }
  }
  ans += K - 1 - cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K >> R;
  for (int i = 0; i < R; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    for (int dir = 0; dir < 4; dir++) {
      int aa = dy[dir] + a;
      int bb = dx[dir] + b;
      int cc = dy[dir] + c;
      int dd = dx[dir] + d;
      if (aa == c && bb == d) {
        board[a][b][dir] = 1;
      }
      if (cc == a && dd == b) {
        board[c][d][dir] = 1;
      }
    }
  }
  for (int i = 0; i < K; i++) {
    cin >> arr[i][0] >> arr[i][1];
    d[arr[i][0]][arr[i][1]] = 1;
  }
  for (int i = 0; i < K; i++) ft(arr[i][0], arr[i][1]);
  cout << ans / 2 << '\n';
}