// https://www.acmicpc.net/problem/10216
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;
int p[3000], N, T;

int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}

void uf(int x, int y) {
  x = find(x); y = find(y);
  if (x < y) p[y] = x;
  else p[x] = y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--) {
    vector<tuple<int, int, int>> v;
    cin >> N;
    for (int i = 0; i < N; i++) p[i] = i;
    for (int i = 0; i < N; i++) {
      int a, b, c; cin >> a >> b >> c;
      for (int j = 0; j < v.size(); j++) {
        int x, y, z;
        tie(x, y, z) = v[j];
        if (pow(x - a, 2) + pow(y - b, 2) <= pow(z + c, 2)) uf(i, j);
      }
      v.push_back({a, b, c});
    }
    set<int> s;
    for (int i = 0; i < N; i++) {find(i); s.insert(p[i]);}
    cout << s.size() << '\n';
  }
}