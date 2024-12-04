// https://www.acmicpc.net/problem/17396
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = pair<long, long>;
long long N, M, d[100001], INF = 2e15 + 1;
vector<ll> v[100001];
bool arr[100001];
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {cin >> arr[i]; d[i] = INF;}
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    v[a].push_back({c, b});
    v[b].push_back({c, a});
  }
  arr[N - 1] = 0;
  pq.push({d[0] = 0, 0});
  while (!pq.empty()) {
    auto [a, b] = pq.top(); pq.pop();
    if (a != d[b]) continue;
    for (auto [c, e] : v[b]) {
      if (arr[e] || d[e] <= a + c) continue;
      pq.push({d[e] = a + c, e});
    }
  }
  if (d[N - 1] == INF) cout << "-1\n";
  else cout << d[N - 1] << '\n';
}