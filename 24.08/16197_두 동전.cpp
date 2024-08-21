// https://www.acmicpc.net/problem/16197
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M, cx = -1, cy = -1, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char board[22][22];
bool vis[22][22][22][22];
queue<tuple<int, int, int, int, int> > q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'o' && cx == -1) {
        cx = j;
        cy = i;
      } else if (board[i][j] == 'o') {
        q.push({cy, cx, i, j, 0});
        vis[cy][cx][i][j] = 1;
      }
    }
  }
  while (!q.empty()) {
    int a, b, c, d, e;
    tie(a, b, c, d, e) = q.front(); q.pop();
    if (e == 10) break;
    for (int dir = 0; dir < 4; dir++) {
      int xx = b + dx[dir];
      int yy = a + dy[dir];
      int nx = d + dx[dir];
      int ny = c + dy[dir];
      int cnt = 0;
      if (board[yy][xx] == '#') {yy = a; xx = b;}
      if (board[ny][nx] == '#') {ny = c; nx = d;}
      if (vis[yy][xx][ny][nx]) continue;
      vis[yy][xx][ny][nx] = 1;
      if (xx == nx && ny == yy) continue;
      if (xx < 1 || yy < 1 || xx > M || yy > N) cnt++;
      if (nx < 1 || ny < 1 || nx > M || ny > N) cnt++;
      if (cnt == 2) continue;
      if (cnt == 1) {
        cout << e + 1 << '\n';
        return 0;
      }
      q.push({yy, xx, ny, nx, e + 1});
    }
  }
  cout << "-1\n";
}