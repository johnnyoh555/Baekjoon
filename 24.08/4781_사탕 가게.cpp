// https://www.acmicpc.net/problem/4781
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
float N, M;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    int m = M * 100 + 0.5f;
    long vis[10001] = {0};
    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
      float a, b; cin >> a >> b;
      int bb = b * 100 + 0.5f;
      v.push_back({a, bb});
      vis[bb] = max(vis[bb], (long)a);
    }
    for (int i = 0; i < v.size(); i++)
      for (int j = 1; j < m; j++)
        if (vis[j] && j + v[i].second <= m) 
            vis[j + v[i].second] = max(vis[j + v[i].second], vis[j] + v[i].first);
    long ans = 0;
    for (int i = 1; i <= m; i++)
      if (ans < vis[i]) ans = vis[i];
    cout << ans << '\n';
  }
}