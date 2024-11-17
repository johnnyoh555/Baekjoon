// https://www.acmicpc.net/problem/5214
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
using namespace std;
unordered_set<int> us[1000];
vector<int> v[100001];
int N, K, M, vis[100001];
bool d[1001];
queue<pair<int, int>> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      int tmp; cin >> tmp;
      us[i].insert(tmp);
      v[tmp].push_back({i});
    }
  }
  for (int i = 0; i < v[1].size(); i++) {
    q.push({v[1][i], 1}); d[v[1][i]] = 1;
  }
  vis[1] = 1;
  while (!q.empty()) {
    int a, c; tie(a, c) = q.front(); q.pop(); 
    for (auto it = us[a].begin(); it != us[a].end(); it++) {
      if (vis[*it]) continue;
      vis[*it] = c + 1;
      for (int i = 0; i < v[*it].size(); i++) {
        if (d[v[*it][i]]) continue;
        d[v[*it][i]] = 1;
        q.push({v[*it][i], c + 1});
      }
    }
  }
  if (vis[N]) cout << vis[N] << '\n';
  else cout << "-1\n";
}