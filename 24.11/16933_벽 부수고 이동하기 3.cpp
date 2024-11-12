// https://www.acmicpc.net/problem/16933
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M, K, ans = -1, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool board[1001][1001], vis[11][1001][1001];
queue<tuple<int, int, int, int>> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    string tmp; cin >> tmp;
    for (int j = 0; j < M; j++)
      board[i + 1][j + 1] = tmp[j] - '0';
  }
  q.push({0, 0, 1, 1});
  vis[0][1][1] = 1;
  while (!q.empty()) {
    int s, c, y, x;
    tie(s, c, y, x) = q.front(); q.pop();
    if (y == N && x == M) {ans = c + 1; break;}
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx <= 0 || ny <= 0 || nx > M || ny > N) continue;
      if (board[ny][nx]) {
        if (s >= K || vis[s + 1][ny][nx]) continue;
        if (c % 2) {
          q.push({s, c + 1, y, x});
        } else {
          q.push({s + 1, c + 1, ny, nx});
          vis[s + 1][ny][nx] = 1;
        }
      } else {
        if (vis[s][ny][nx]) continue;
        vis[s][ny][nx] = 1;
        q.push({s, c + 1, ny, nx});
      }
    }
  }
  if (ans == 2e9) ans = -1;
  cout << ans << '\n';
}