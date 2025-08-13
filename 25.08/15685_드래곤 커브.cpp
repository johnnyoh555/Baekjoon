// https://www.acmicpc.net/problem/15685
#include <iostream>
#include <vector>
using namespace std;
bool board[101][101];
int N, x, y, st, g, dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0}, ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int n = 0; n < N; n++) {
    vector<int> v;
    cin >> x >> y >> st >> g;
    v.push_back(st);
    for (int i = 0; i < g; i++) {
      int j = v.size();
      while (j--)
        v.push_back((v[j] + 1) % 4);
    }
    board[y][x] = 1;
    for (int i = 0; i < v.size(); i++) {
      y += dy[v[i]];
      x += dx[v[i]];
      board[y][x] = 1;
    }
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (board[i][j] && board[i + 1][j] 
        && board[i][j + 1] && board[i + 1][j + 1])
        ans++;
    }
  }
  cout << ans << '\n';
}