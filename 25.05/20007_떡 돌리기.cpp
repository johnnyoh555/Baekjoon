// https://www.acmicpc.net/problem/20007
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, X, Y, sum, ans, d[1001], INF = 1e9;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> X >> Y;
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  fill(d, d + 1001, INF);
  d[Y] = 0;
  pq.push({0, Y});
  while (!pq.empty()) {
    auto [s, node] = pq.top(); pq.pop();
    if (d[node] != s) continue;
    for (auto [nx, c] : v[node]) {
      if (d[nx] <= s + c) continue;
      d[nx] = s + c;
      pq.push({d[nx], nx});
    }
  }
  int sum = 0, ans = 0;
  sort(d, d + N);
  for (int i = 1; i < N; i++) {
    int tmp = d[i] * 2;
    if (tmp > X) {
      cout << "-1\n";
      return 0;
    }
    if (sum + tmp > X) {
      ans++;
      sum = tmp;
    } else {
      sum += tmp;
    }
  }
  if (sum) ans++;
  cout << ans << '\n';
}