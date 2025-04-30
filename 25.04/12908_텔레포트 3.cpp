// https://www.acmicpc.net/problem/12908
#include <iostream>
#include <cmath>
using namespace std;
long arr[7][4], ans = 1e18;
bool vis[7];

void dfs(int x, int y, long c) {
  if (vis[0] == 1) {
    if (c < ans) ans = c; 
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    long tmp = abs(arr[i][0] - x) + abs(arr[i][1] - y);
    if (i) tmp += 10;
    dfs(arr[i][2], arr[i][3], tmp + c);
    vis[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y;
  cin >> x >> y >> arr[0][0] >> arr[0][1];
  arr[0][2] = arr[0][0];
  arr[0][3] = arr[0][1];
  for (int i = 1; i <= 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> arr[i][j];
      arr[i + 3][(j + 2) % 4] = arr[i][j];
    }
  }
  dfs(x, y, 0);
  cout << ans << '\n';
}