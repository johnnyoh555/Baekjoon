// https://www.acmicpc.net/problem/1939
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> v[10001];
int N, M, f, t, ans;

bool check(int a) {
  bool vis[10001] = {};
  queue<int> q;
  vis[f] = 1;
  q.push(f);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    for (auto nxt : v[x]) {
      if (vis[nxt.first] || nxt.second < a) continue;
      vis[nxt.first] = 1;
      q.push(nxt.first);
    }
  }
  return vis[t] == 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  cin >> f >> t;
  int st = 1, en = 1e9 + 1;
  while (st < en) {
   int mid = (st + en) / 2;
   if (check(mid)) {
    st = mid + 1;
    if (ans < mid) ans = mid;
   } else {
    en = mid;
   }
  }
  cout << ans << '\n';
}