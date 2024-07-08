// https://www.acmicpc.net/problem/16562
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<int> s[10001];
vector<pair<int, int> > p;
bool vis[10001];
int N, M, k, cnt, ans;

void dfs(int x) {
  for (auto it =  s[x].begin(); it != s[x].end(); it++) {
    if(vis[*it]) continue;
    cnt++;
    vis[*it] = 1;
    dfs(*it);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> k;
  for (int i = 1; i <= N; i++) {
    int tmp; cin >> tmp;
    p.push_back({tmp, i});
  }
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    if (a == b) continue;
    s[a].insert(b);
    s[b].insert(a);
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < p.size(); i++) {
    if (vis[p[i].second]) continue;
    vis[p[i].second] = 1;
    cnt++;
    ans += p[i].first;
    dfs(p[i].second);
  }
  if (cnt != N || ans > k) cout << "Oh no\n";
  else cout << ans << '\n';
}