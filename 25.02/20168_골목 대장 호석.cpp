// https://www.acmicpc.net/problem/20168
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;
int N, M, A, B, C, d[2][11], ans = 2e9;
vector<pair<int, int>> v[11];
priority_queue<tuple<int, int, int>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> A >> B >> C;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  fill(&d[0][0], &d[1][0] + 11, 1e9);
  d[0][A] = 0;
  d[1][A] = 0;
  pq.push({0, 0, A});
  while (!pq.empty()) {
    int a, b, c;
    tie(a, b, c) = pq.top(); pq.pop();
    if (c == B) {
      if (a < ans) ans = a;
      continue;
    }
    for (auto nxt : v[c]) {
      int tmp = max(nxt.second, a);
      if (d[0][nxt.first] <= tmp && d[1][nxt.first] <= b + nxt.second) continue;
      if (b + nxt.second > C) continue;
      d[0][nxt.first] = tmp;
      d[1][nxt.first] = b + nxt.second;
      pq.push({tmp, b + nxt.second, nxt.first});
    }
  }
  if (ans == 2e9) ans = -1;
  cout << ans << '\n';
}