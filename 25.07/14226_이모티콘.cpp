// https://www.acmicpc.net/problem/14226
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int s;
bool d[2100][2100];
queue<tuple<int, int, int>> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  d[1][0] = 1;
  q.push({1, 0, 0});
  while (!q.empty()) {
    auto [c, t, p] = q.front(); q.pop();
    if (c == s) {
      cout << t << '\n';
      break;
    }
    if (!d[c][c]) {
      d[c][c] = 1;
      q.push({c, t + 1, c});
    }
    if (c + p < 2100 && !d[c + p][p]) {
      d[c + p][p] = 1;
      q.push({c + p, t + 1, p});
    }
    if (c - 1 && !d[c - 1][p]) {
      d[c - 1][p] = 1;
      q.push({c - 1, t + 1, p});
    }
  }
}