// https://www.acmicpc.net/problem/14497
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
char board[301][301];
bool vis[301][301];
int N, M, ans, x1, x2, y1, y2, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> y1 >> x1 >> y2 >> x2;
  for (int i = 0; i < N; i++) {
    string str; cin >> str;
    for (int j = 0; j < M; j++)
      board[i][j] = str[j];
  }
  q.push({0, y1 - 1, x1 - 1});
  vis[y1 - 1][x1 - 1] = 1;
  while (!q.empty()) {
    int a, b, c;
    tie(c, a, b) = q.top(); q.pop();
    if (board[a][b] == '#') {
      ans = c;
      break;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = b + dx[dir];
      int ny = a + dy[dir];
      if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;
      if (vis[ny][nx]) continue;
      vis[ny][nx] = 1;
      if (board[ny][nx] != '0') q.push({c + 1, ny, nx});
      else q.push({c, ny, nx});
    }
  }
  cout << ans << '\n';
}
