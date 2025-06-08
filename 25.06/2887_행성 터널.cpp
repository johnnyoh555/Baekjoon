// https://www.acmicpc.net/problem/2887
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int N, p[100001], cnt;
vector<pair<int, int>> f, s, t;
vector<tuple<int, int, int>> v;
long ans;

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool IsGroup(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return true;
  if (p[x] == p[y]) p[x]--;
  if (p[x] < p[y]) p[y] = x;
  else p[x] = y;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b, c; cin >> a >> b >> c;
    f.push_back({a, i});
    s.push_back({b, i});
    t.push_back({c, i});
  }
  fill(p, p + 100000, -1);
  sort(f.begin(), f.end());
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  for (int i = 1; i < f.size(); i++) {
    v.push_back({abs(f[i].first - f[i - 1].first), f[i].second, f[i - 1].second});
    v.push_back({abs(s[i].first - s[i - 1].first), s[i].second, s[i - 1].second});
    v.push_back({abs(t[i].first - t[i - 1].first), t[i].second, t[i - 1].second});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    auto [c, x, y] = v[i];
    if (IsGroup(x, y)) continue;
    ans += c;
    cnt++;
    if (cnt == N - 1) break;
  }
  cout << ans << '\n';
}