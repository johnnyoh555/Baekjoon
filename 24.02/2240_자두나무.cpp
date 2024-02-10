// https://www.acmicpc.net/problem/2240

#include <iostream>

using namespace std;

int d[1001][32];
int b[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T, W;
  cin >> T >> W;
  for (int i = 1; i <= T; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= T; i++) {
    for (int j = 0; j <= W && j <= i; j++) {
      if (!j)
        d[i][j] = d[i - 1][j];
      else
        d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]);
      if (j % 2 != b[i] % 2) d[i][j]++;
    }
  }
  int max = 0;
  for (int i = 0; i <= W; i++) {
    if (d[T][i] > max) max = d[T][i];
  }
  cout << max << '\n';
}
