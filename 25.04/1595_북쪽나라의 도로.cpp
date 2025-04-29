// https://www.acmicpc.net/problem/1595
#include <iostream>
#include <vector>
using namespace std;
int a, b, c, ans;
vector<pair<int, int>> v[10001];
bool vis[10001];

int dfs(int x) {
  int tmp1 = 0, tmp2 = 0;
  for (auto nxt : v[x]) {
    if (vis[nxt.first]) continue;
    vis[nxt.first] = 1;
    int tmp = dfs(nxt.first) + nxt.second;
    if (tmp > tmp1) {
      tmp2 = tmp1;
      tmp1 = tmp;
    } else if (tmp > tmp2) {
      tmp2 = tmp;
    }
    if (ans < tmp1 + tmp2) ans = tmp1 + tmp2;
  }
  return tmp1;
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