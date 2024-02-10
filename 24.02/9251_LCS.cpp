// https://www.acmicpc.net/problem/9251

#include <iostream>

using namespace std;

int d[1004][1004];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string N;
  string M;
  cin >> N >> M;

  int x = N.size();
  int y = M.size();

  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      if (N[i - 1] == M[j - 1])
        d[i][j] = d[i - 1][j - 1] + 1;
      else
        d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    }
  }
  cout << d[x][y] << '\n';
}