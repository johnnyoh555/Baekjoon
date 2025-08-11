// https://www.acmicpc.net/problem/2580
#include <iostream>
#include <vector>
using namespace std;
int board[9][9];
bool sq[9][10], rl[9][10], dl[9][10], flag;
vector<pair<int, int>> v;

void dfs(int dep) {
  if (dep == v.size()) {
    flag = 1;
    return;
  }
  auto [y, x] = v[dep];
  for (int i = 1; i <= 9; i++) {
    if (!sq[y / 3 * 3 + x / 3][i] && !rl[y][i] && !dl[x][i]) {
      sq[y / 3 * 3 + x / 3][i] = 1;
      board[y][x] = i;
      rl[y][i] = 1;
      dl[x][i] = 1;
      dfs(dep + 1);
      if (flag) return;
      board[y][x] = 0;
      dl[x][i] = 0;
      rl[y][i] = 0;
      sq[y / 3 * 3 + x / 3][i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
      if (board[i][j]) {
        sq[i / 3 * 3 + j / 3][board[i][j]] = 1;
        rl[i][board[i][j]] = 1;
        dl[j][board[i][j]] = 1;
      } else {
        v.push_back({i, j});
      }
    }
  }
  dfs(0);
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cout << board[i][j] << (j != 8 ? ' ' : '\n');
}