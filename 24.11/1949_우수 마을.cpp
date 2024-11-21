// https://www.acmicpc.net/problem/1949
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, p[10001], ans, dp[2][10001];
bool vis[10001];
vector<int> v[10001];

void dfs(int x) {
  vis[x] = 1;
  dp[1][x] = p[x];
  for (int nxt : v[x]) {
    if (vis[nxt]) continue;
    dfs(nxt);
    dp[0][x] += max(dp[0][nxt], dp[1][nxt]);
    dp[1][x] += dp[0][nxt];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> p[i];
  for (int i = 1; i < N; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  cout << max(dp[0][1], dp[1][1]) << '\n';
}