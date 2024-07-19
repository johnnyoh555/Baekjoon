// https://www.acmicpc.net/problem/3980
#include <iostream>
using namespace std;
int T, arr[11][11], ans;
bool vis[11];

void dfs(int sum, int dep) {
  if (dep == 11) {
    if (sum > ans) ans = sum;
    return;
  }
  for (int i = 0; i < 11; i++) {
    if (!arr[dep][i] || vis[i]) continue;
    vis[i] = 1;
    dfs(sum + arr[dep][i], dep + 1);
    vis[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    ans = 0;
    for (int i = 0; i < 11; i++)
      for (int j = 0; j < 11; j++)
        cin >> arr[i][j];
    dfs(0, 0);
    cout << ans << '\n';
  }
}