// https://www.acmicpc.net/problem/2250
#include <iostream>
#include <algorithm>
using namespace std;
int node[10001][2], dep[10001], N, ans = 1, lev = 1, cnt, vis[10001];

void dfs(int x, int d) {
  if (node[x][0] != -1)
    dfs(node[x][0], d + 1);
  cnt++;
  if (cnt < dep[d]) {
    dep[d] = cnt;
  }
  if (ans < cnt - dep[d] + 1) {
    ans = cnt - dep[d] + 1;
    lev = d;
  } else if (ans == cnt - dep[d] + 1 && lev > d) {
    lev = d;
  }
  if (node[x][1] != -1)
    dfs(node[x][1], d + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b, c; cin >> a >> b >> c;
    node[a][0] = b; node[a][1] = c;
    if (b != -1) vis[b]++;
    if (c != -1) vis[c]++;
  }
  fill(dep, dep + N + 1, 2e9);
  for (int i = 1; i <= N; i++) {
    if (!vis[i]) dfs(i, 1);
  }
  cout << lev << ' ' << ans << '\n';
}
