// https://www.acmicpc.net/problem/2162
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, p[3001], groups, ans, d[3001];
vector<pair<pair<int, int>, pair<int, int>>> v;

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void makegroup (int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (p[x] == p[y]) p[x]--;
  if (p[x] < p[y]) p[y] = x;
  else p[x] = y;
}

long ccw(pair<int, int>& x, pair<int, int>& y, pair<int, int>& z) {
  return 1ll * (y.first - x.first) * (z.second - x.second) - 1ll * (y.second - x.second) * (z.first - x.first);
}

bool check(int i, int j) {
  auto p1 = v[i].first, p2 = v[i].second, p3 = v[j].first, p4 = v[j].second;  
  long a = ccw(p1, p2, p3) * ccw(p1, p2, p4); 
  long b = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  if (a == 0 && b == 0) {
    if (p1 > p2) swap(p1, p2);
    if (p3 > p4) swap(p3, p4);
    return (p2 >= p3 && p4 >= p1);
  }
  return a <= 0 && b <= 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  fill(p, p + 3001, -1);
  for (int i = 0; i < N; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    v.push_back({{a, b}, {c, d}});
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (check(i, j)) makegroup(i, j);
    }
  }
  for (int i = 0; i < N; i++) {
    int idx = find(i);
    if (!d[idx]) groups++;
    d[idx]++;
    if (d[idx] > ans) ans = d[idx];
  }
  cout << groups << '\n';
  cout << ans << '\n';
}