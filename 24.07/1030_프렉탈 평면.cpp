// https://www.acmicpc.net/problem/1030
#include <iostream>
#include <cmath>
using namespace std;
int s, N, K, R1, R2, C1, C2;
bool ans[50][50];

void black(int p, int y, int x) {
  int sty, stx, eny, enx;
  int l = pow(N, p);
  if (y < R1) sty = R1;
  else sty = y;
  if (x < C1) stx = C1;
  else stx = x;
  if (y + l - 1 > R2) eny = R2;
  else eny = y + l - 1;
  if (x + l - 1 > C2) enx = C2;
  else enx = x + l - 1;
  for (int i = sty; i <= eny; i++) {
    for (int j = stx; j <= enx; j++) {
      ans[i - R1][j - C1] = 1;
    }
  }
}

void dfs(int p, int y, int x) {
  if (p == 0) return;
  int l = pow(N, p);
  int m = (N - K) / 2;
  for (int i = y; i < y + l; i += (l / N)) {
    for (int j = x; j < x + l; j += (l / N)) {
      if (i + (l / N) - 1 < R1 || i > R2 || j + (l / N) - 1 < C1 || j > C2) continue;
      if (i >= y + (l / N) * m && i < y + l - (l / N) * m && j >= x + (l / N) * m && j < x + l - (l / N) * m) {
        black(p - 1, i, j);
      } else {
        dfs(p - 1, i, j);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

  dfs(s, 0, 0);

  for (int i = 0; i <= R2 - R1; i++) {
    for (int j = 0; j <= C2 - C1; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}
