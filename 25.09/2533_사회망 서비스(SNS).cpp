// https://www.acmicpc.net/problem/2533
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, dp[1000001][2];
bool vis[1000001];
vector<int> v[1000001];

void dfs(int node) {
  vis[node] = 1;
  for (auto nxt : v[node]) {
    if (vis[nxt]) continue;
    dfs(nxt);
    dp[node][0] += dp[nxt][1]; 
    dp[node][1] += min(dp[nxt][0], dp[nxt][1]);
  }
  dp[node][1] += 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  cout << min(dp[1][0], dp[1][1]) << '\n';
}