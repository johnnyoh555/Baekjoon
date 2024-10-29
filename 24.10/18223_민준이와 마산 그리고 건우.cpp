// https://www.acmicpc.net/problem/18223
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int V, E, P;
vector<pair<int, int>> v[5001];

int ft(int from, int to) {
  int d[5001];
  fill(d, d  + 5002, 2e9);
  d[from] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, from});
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (cur.first != d[cur.second]) continue;
    for (auto nxt : v[cur.second]) {
      if (d[nxt.second] <= cur.first + nxt.first) continue;
      d[nxt.second] = cur.first + nxt.first;
      pq.push({d[nxt.second], nxt.second});
    }
  }
  return d[to];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E >> P;
  for (int i = 0; i < E; i++) {
    int a, b, c; cin >> a >> b >> c;
    v[a].push_back({c, b});
    v[b].push_back({c, a});
  }
  if (ft(1, V) == ft(1, P) + ft(P, V)) cout << "SAVE HIM\n";
  else cout << "GOOD BYE\n";
}