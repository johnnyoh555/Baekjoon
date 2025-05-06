// https://www.acmicpc.net/problem/20182
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, A, B, C, st, en = 21, ans = 2e9;
vector<pair<int, int>> v[100001];

bool ft(int x) {
  int vis[100001];
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  fill(vis, vis + N + 1, 1e9);
  vis[A] = 0;
  pq.push({0, A});
  while (!pq.empty()) {
    auto [a, b] = pq.top(); pq.pop();
    if (vis[b] != a) continue;
    for (auto nxt : v[b]) {
      if (nxt.second > x) continue;
      if (vis[nxt.first] <= a + nxt.second) continue;
      vis[nxt.first] = a + nxt.second;
      pq.push({vis[nxt.first], nxt.first});
    }
  }
  if (vis[B] <= C) return true;
  else return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> A >> B >> C;
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  while (st < en) {
    int mid = (st + en) / 2;
    if (ft(mid)) {
      en = mid;
      if (mid < ans) ans = mid;
    } else {
      st = mid + 1;
    }
  }
  if (ans == 2e9) ans = -1;
  cout << ans << '\n';
}