// https://www.acmicpc.net/problem/18428
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int> > p;
int N;
char board[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool ans;

void check() {
  for (int i = 0; i < p.size(); i++) {
    int x, y;
    x = p[i].second;
    y = p[i].first;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x;
      int ny = y;
      while (true) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 1 || ny < 1 || nx > N || ny > N) break;
        if (board[ny][nx] == 'O') break;
        if (board[ny][nx] == 'S') return;
      }
    }
  }
  ans = 1;
}

void dfs(int y, int x, int dep) {
  if (dep == 2 || ans) {
    check();
    return;
  }
  for (int i = y; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == y && j <= x) continue;
      if (board[i][j] != 'X') continue;
      board[i][j] = 'O';
      dfs(i, j, dep + 1);
      board[i][j] = 'X';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'T') {
        p.push_back({i, j});
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j] != 'X') continue;
      board[i][j] = 'O';
      dfs(i, j, 0);
      board[i][j] = 'X';
    }
  }
  if (ans) cout << "YES\n";
  else cout << "NO\n";
}