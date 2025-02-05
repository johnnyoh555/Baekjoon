// https://www.acmicpc.net/problem/1277
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N, W;
double M, d[1001];
vector<pair<int, int>> coo;
vector<pair<int, double>> v[1001];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> W >> M;
  for (int i = 0; i < N; i++) {
    int y, x; cin >> y >> x;
    coo.push_back({y, x});
  }
  for (int i = 0; i < W; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back({b, 0});
    v[b].push_back({a, 0});
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double tmp = sqrt(pow(coo[i].first - coo[j].first, 2) + pow(coo[i].second - coo[j].second, 2));
      if (tmp > M) continue;
      v[i + 1].push_back({j + 1, tmp});     
      v[j + 1].push_back({i + 1, tmp});     
    }
  }
  fill(d, d + 1001, 2e9);
  d[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    double c;
    int a;
    tie(c, a) = pq.top(); pq.pop();
    if (d[a] != c) continue;
    for (auto nxt : v[a]) {
      if (c + nxt.second >= d[nxt.first]) continue;
      d[nxt.first] = c + nxt.second;
      pq.push({d[nxt.first], nxt.first}); 
    }
  }
  cout << (int)(d[N] * 1000) << '\n';
}