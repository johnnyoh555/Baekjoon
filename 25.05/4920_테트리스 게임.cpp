// https://www.acmicpc.net/problem/4920
#include <iostream>
#include <algorithm>
using namespace std;
int N, ans, board[101][101], cnt = 1;
int arr[9][3][2] = {{{0, 1}, {0, 2}, {0, 3}}, {{0, 1}, {1, 1}, {1, 2}}, {{0, 1}, {0, 2}, {1, 2}}, {{0, 1}, {1, 1}, {0, 2}}, {{0, 1}, {1, 0}, {1, 1}}, \
                  {{1, 0}, {2, 0}, {3, 0}}, {{1, 0}, {1, -1}, {2, -1}}, {{1, 0}, {2, 0}, {2, -1}}, {{1, 0}, {1, -1}, {2,0}}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    cin >> N;
    if (!N) break;
    ans = -2e9;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> board[i][j];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int dir = 0; dir < 9; dir++) {
          for (int k = 0; k < 2; k++) {
            int m = k ? 1 : -1;
            int tmp = board[i][j];
            for (int l = 0; l < 3; l++) {
              int nx = j + m * arr[dir][l][1];
              int ny = i + m * arr[dir][l][0];
              if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                m = 0;
                break;
              }
              tmp += board[ny][nx];
            }
            if (!m) continue;
            if (tmp > ans) ans = tmp;
          }
        }
      }
    }
    cout << cnt << ". " << ans << '\n';
    cnt++;
  }
}

