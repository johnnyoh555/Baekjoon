// https://www.acmicpc.net/problem/2370
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
map<int, int> m;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b + 1});
  }
  m[v[n - 1].first] = v[n - 1].second;
  for (int i = n - 2; i >= 0; i--) {
    auto [st, en] = v[i];
    auto it = m.upper_bound(st);
    if (it != m.begin()) {
      auto pre = prev(it);
      if (pre->second >= st) {
        if (pre->second >= en) {
          n--;
          continue;
        }
        st = pre->first;
      }
    }
    auto it2 = m.upper_bound(en);
    if (it2 != m.begin()) {
      it2 = prev(it2);
      en = max(en, it2->second);
      bool flag = 1;
      while (flag) {
        auto tmp = it2;
        if (it2 != m.begin()) it2 = prev(it2);
        else flag = 0;
        if (tmp->first < st) break;
        else m.erase(tmp);
      }
    }
    m[st] = en;
  }
  cout << n << '\n';
}