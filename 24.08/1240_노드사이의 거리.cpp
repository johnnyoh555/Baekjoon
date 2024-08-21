// https://www.acmicpc.net/problem/1240
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, x, y, ans;
vector<pair<int, int> > v[1001];
bool vis[1001];

void dfs(int idx, int len) {
  if (ans) return;
  if (idx == y) {
    ans = len;
    return;
  }
  for (auto nxt : v[idx]) {
    if (vis[nxt.first]) continue;
    vis[nxt.first] = 1;
    dfs(nxt.first, len + nxt.second);
    vis[nxt.first] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N - 1; i++) {
    int a, b, c; cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    ans = 0;
    vis[x] = 1;
    dfs(x, 0);
    vis[x] = 0;
    cout << ans << '\n';
  }
}