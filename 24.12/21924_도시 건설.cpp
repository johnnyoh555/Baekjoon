// https://www.acmicpc.net/problem/21924
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
long N, M, sum, p[100001], cnt;
vector<tuple<int, int, int>> v;

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool IsGroup(int u, int v) {
  u = find(u); v = find(v);
  if (u == v) return true;
  if (p[u] == p[v]) p[u]--;
  if (p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    v.push_back({c, a, b});
    sum += c;
  }
  sort(v.begin(), v.end());
  fill(p, p + N + 1, -1);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    tie(c, a, b) = v[i];
    if (IsGroup(a, b)) continue;
    cnt++;
    sum -= c;
    if (cnt == N - 1) break;
  }
  if (cnt == N - 1) cout << sum << '\n';
  else cout << "-1\n";
}
