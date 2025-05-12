// https://www.acmicpc.net/problem/5913
#include <iostream>
using namespace std;
int K, cnt = 23, ans, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[6][6];

void dfs(int y, int x, int n, int m) {
  if (y == n && x == m) {
    if (cnt == -1) ans++;
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = dx[i] + x;
    int ny = dy[i] + y;
    if (nx < 1 || nx > 5 || ny < 1 || ny > 5) continue;
    if (vis[ny][nx]) continue;
    for (int j = 0; j < 4; j++) {
      int nm = dx[j] + m;
      int nn = dy[j] + n;
      if (nm < 1 || nm > 5 || nn < 1 || nn > 5) continue;
      if (vis[nn][nm]) continue;
      vis[ny][nx] = 1;
      vis[nn][nm] = 1;
      cnt -= 2;
      dfs(ny, nx, nn, nm);
      vis[ny][nx] = 0;
      vis[nn][nm] = 0;
      cnt += 2;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K;
  for (int i = 0; i < K; i++) {
    int y, x; cin >> y >> x;
    vis[y][x] = 1;
    cnt--;
  }
  vis[1][1] = 1;
  vis[5][5] = 1;
  dfs(1, 1, 5, 5);
  cout << ans << '\n';
}