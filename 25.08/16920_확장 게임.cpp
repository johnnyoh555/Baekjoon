// https://www.acmicpc.net/problem/16920
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M, P, s[10], ans[10], turn, board[1001][1001], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, flag;
queue<tuple<int, int, int>> q[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> P;
  for (int i = 1; i <= P; i++) cin >> s[i];
  for (int i = 0; i < N; i++) {
    string tmp; cin >> tmp;
    for (int j = 0; j < M; j++) {
      board[i][j] = tmp[j];
      if (0 < board[i][j] - '0' && board[i][j] - '0' <= P) {
        board[i][j] -= '0';
        q[board[i][j]].push({i, j, 0});
        ans[board[i][j]]++;
        flag++;
      }
    }
  }
  while (flag) {
    turn++;
    for (int i = 1; i <= P; i++) {
      while (!q[i].empty()) {
        auto [y, x, t] = q[i].front();
        if (t == turn * s[i]) break;
        q[i].pop(); flag--;
        for (int dir = 0; dir < 4; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
          if (board[ny][nx] != '.') continue;
          board[ny][nx] = i;
          flag++;
          ans[i]++;
          q[i].push({ny, nx, t + 1});
        }
      }
    }
  }
  for (int i = 1; i <= P; i++) cout << ans[i] << (i != P ? ' ' : '\n');
}