// https://www.acmicpc.net/problem/1595
#include <iostream>
#include <vector>
using namespace std;
int a, b, c, ans;
vector<pair<int, int>> v[10001];
bool vis[10001];

int dfs(int x) {
  int first = 0, second = 0;
  for (auto [node, cost] : v[x]) {
    if (vis[node]) continue;
    vis[node] = 1;
    int tmp = dfs(node) + cost;
    if (tmp > first) {
      second = first;
      first = tmp;
    } else if (tmp > second) {
      second = tmp;
    }
    if (ans < first + second) ans = first + second;
  }
  return first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> a >> b >> c) {
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  vis[1] = 1;
  dfs(1);
  cout << ans << '\n';
}