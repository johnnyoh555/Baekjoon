// https://www.acmicpc.net/problem/15591
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, Q, k, l, cnt;
vector<pair<int,int> > v[5001];
bool vis[5001];

void dfs(int node, int s) {
  if (s >= k) cnt++;
  for (auto nxt : v[node]) {
    if (vis[nxt.first]) continue;
    vis[nxt.first] = 1;
    dfs(nxt.first, min(s, nxt.second));
    vis[nxt.first] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q;
  for (int i = 0; i < N - 1; i++) {
    int a, b, c; cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  for (int i = 0; i < Q; i++) {
    cin >> k >> l;
    cnt = -1;
    vis[l] = 1;
    dfs(l, 2e9 + 1);
    vis[l] = 0;
    cout << cnt << '\n';
  }
}