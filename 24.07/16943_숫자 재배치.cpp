// https://www.acmicpc.net/problem/16943
#include <iostream>
using namespace std;
int ans = -1, b;
bool vis[11];
string a;

void dfs(int sum, int dep) {
  if (dep == a.size()) {
    if (sum < b && sum > ans) ans = sum;
    return;
  }
  for (int i = 0; i < a.size(); i++) {
    if (vis[i]) continue;
    if (dep == 0 && a[i] == '0') continue;
    vis[i] = 1;
    dfs(sum * 10 + a[i] - '0', dep + 1);
    vis[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  dfs(0, 0);
  cout << ans << '\n';
}