// https://www.acmicpc.net/problem/14890
#include <iostream>
using namespace std;
int board[101][101], N, L, ans;

void ft(int x, int y, int dx, int dy) {
  int cnt = 0, can = 0, prev = board[y][x];
  while (x < N && y < N) {
    if (prev == board[y][x]) {
      cnt++;
    } else if (prev + 1 == board[y][x] && can == 1) {
      cnt = 1;
      can = 0;
    } else if (prev - 1 == board[y][x] && can != -1) {
      cnt = 1;
      can = -1;
    } else {
      return;
    }
    if (cnt >= L && can == -1) {
      cnt = 0;
      can = 0;
    } else if (cnt >= L && can == 0) {
      can = 1;
    }
    prev = board[y][x];
    x += dx;
    y += dy;
  }
  if (can == -1) return;
  ans++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> L;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> board[i][j];
  for (int i = 0; i < N; i++) {
    ft(i, 0, 0, 1);
    ft(0, i, 1, 0);
  }
  cout << ans << '\n';
}