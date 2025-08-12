// https://www.acmicpc.net/problem/16166
#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
long long N, T, ans = -1;
set<long long> s[10];
vector<int> v[10];
queue<pair<int, int>> q;
bool vis[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int c; cin >> c;
    for (int j = 0; j < c; j++) {
      long long tmp; cin >> tmp;
      s[i].insert(tmp);
    }
  }
  cin >> T;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (auto it = s[i].begin(); it != s[i].end(); it++) {
        if (s[j].find(*it) != s[j].end()) {
          v[i].push_back(j);
          v[j].push_back(i);
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (s[i].find(0) != s[i].end()) {
      vis[i] = 1;
      q.push({i, 0});
    }
  }
  while (!q.empty()) {
    auto [a, b] = q.front(); q.pop();
    if (s[a].find(T) != s[a].end()) {
       ans = b;
       break;
    }
    for (auto nxt : v[a]) {
      if (vis[nxt]) continue;
      vis[nxt] = 1;
      q.push({nxt, b + 1});
    }
  }
  cout << ans << '\n';
}