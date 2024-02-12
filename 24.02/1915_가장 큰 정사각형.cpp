// https://www.acmicpc.net/problem/1915

#include <iostream>

using namespace std;

short d[1001][1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int max = 0;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= m; j++) {
      d[i][j] = str[j - 1] - '0';
      if (d[i][j]) {
        d[i][j] = min(min(d[i - 1][j - 1], d[i - 1][j]), d[i][j - 1]) + 1;
      }
      if (d[i][j] > max) max = d[i][j];
    }
  }
  cout << max * max << '\n';
}