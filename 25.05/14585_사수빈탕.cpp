// https://www.acmicpc.net/problem/14585
#include <iostream>
#include <algorithm>
using namespace std;
int d[302][302], N, M, ans;
bool board[302][302];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int x, y; cin >> y >> x;
    board[y + 1][x + 1] = 1;
  }
  for (int i = 1; i <= 301; i++)
    for (int j = 1; j <= 301; j++) {
      if (i + j - 2 >= M) continue;
      d[i][j] = max(d[i - 1][j], d[i][j - 1]);
      if (board[i][j]) d[i][j] += M - (i + j - 2);
      if (ans < d[i][j]) ans = d[i][j];
    }
  cout << ans << '\n';
}