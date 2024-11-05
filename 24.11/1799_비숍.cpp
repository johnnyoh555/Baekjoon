// https://www.acmicpc.net/problem/1799
#include <iostream>
using namespace std;
int N, ans, mx;
bool board[10][10], vis[10][10]; 

bool CanPlace(int y, int x) {
  int ny = y, nx = x;
  while (ny >= 0 && nx >= 0) {
    if (vis[ny][nx]) return false;
    ny--; nx--;
  }
  ny = y; nx = x;
  while (ny >= 0 && nx < N) {
    if (vis[ny][nx]) return false;
    ny--; nx++;
  }
  return true;
}

void dfs(int y, int x, int sum) {
  int nx = x + 2, ny = y;
  if (y == N) {
    if (mx < sum) mx = sum;
    return;
  }
  if (nx >= N) {
    ny++;
    nx -= N;
    if (N % 2 == 0) {
      if (nx == 0) nx++;
      else nx--;
    }
  }
  if (board[y][x] && CanPlace(y, x)) {
    vis[y][x] = 1;
    dfs(ny, nx, sum + 1);
    vis[y][x] = 0;
  }
  dfs(ny, nx, sum);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> board[i][j];
  dfs(0, 0, 0);
  ans += mx; mx = 0;
  dfs(0, 1, 0);
  cout << ans + mx << '\n';
}