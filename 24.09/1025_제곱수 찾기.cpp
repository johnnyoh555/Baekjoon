// https://www.acmicpc.net/problem/1025
#include <iostream>
#include <cmath>
using namespace std;
string board[9];
int N, M, ans = -1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> board[i];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = -8; k < 9; k++) {
        for (int l = -8; l < 9; l++) {
          string str;
          str += board[i][j];
          if (!k && !l) {
            int b = stoi(str);
            int a = sqrt(b);
            if (b == a * a && b > ans) ans = b;
            continue;
          }
          int x = j, y = i;
          while (1) {
            x += l;
            y += k;
            if (x < 0 || y < 0 || x >= M || y >= N) break;
            str += board[y][x];
            if (board[y][x] == 2 || board[y][x] == 3 || board[y][x] == 7 || board[y][x] == 8) continue;
            int b = stoi(str);
            int a = sqrt(b);
            if (b == a * a && b > ans) ans = b;
          }
        }
      }
    }
  }
  cout << ans << '\n';
}