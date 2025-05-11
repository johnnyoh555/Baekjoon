// https://www.acmicpc.net/problem/17394
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int T, N, A, B;
bool d[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  d[1] = 1;
  for (int i = 2; i <= 100000; i++) {
    if (d[i]) continue;
    for (int j = i + i; j <= 100000; j += i)
      d[j] = 1;
  }
  for (int i = 0; i < T; i++) {
    cin >> N >> A >> B;
    int ans = -1;
    bool vis[2000001] = {};
    queue<pair<int, int>> q;
    vis[N] = 1;
    q.push({N, 0});
    while (!q.empty()) {
      auto [x, c] = q.front(); q.pop();
      if (A <= x && x <= B && !d[x]) {
        ans = c;
        break;
      }
      if (x / 2 && !vis[x / 2]) {
        vis[x / 2] = 1;
        q.push({x / 2, c  + 1});
      }
      if (x / 3 && !vis[x / 3]) {
        vis[x / 3] = 1;
        q.push({x / 3, c  + 1});
      }
      if (x - 1 && !vis[x - 1]) {
        vis[x - 1] = 1;
        q.push({x - 1, c  + 1});
      }
      if (!vis[x + 1]) {
        vis[x + 1] = 1;
        q.push({x + 1, c  + 1});
      }
    }
    cout << ans << '\n';
  }
}