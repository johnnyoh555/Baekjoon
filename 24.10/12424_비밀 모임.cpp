// https://www.acmicpc.net/problem/13424
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N, M, K, ans = 0, mn = 2e9; cin >> N >> M;
    vector<pair<int, int> > v[101];
    for (int i = 0; i < M; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      v[a].push_back({c, b});
      v[b].push_back({c, a});
    }
    cin >> K;
    int arr[101];
    for (int i = 0; i < K; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
      int d[101];
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      fill(d, d + 102, 2e9);
      d[i] = 0;
      pq.push({0, i});
      while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (a != d[b]) continue;
        for (auto nxt : v[b]) {
          if (d[nxt.second] <= a + nxt.first) continue;
          d[nxt.second] = a + nxt.first;
          pq.push({d[nxt.second], nxt.second});
        }
      }
      int sum = 0;
      for (int i = 0; i < K; i++) sum += d[arr[i]];
      if (sum < mn) {
        mn = sum;
        ans = i;
      }
    }
    cout << ans << '\n';
  }
}