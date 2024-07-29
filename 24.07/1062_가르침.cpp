// https://www.acmicpc.net/problem/1062
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, ans;
bool arr[50][26], d[26];


void check() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    bool flag = 0;
    for (int j = 0; j < 26; j++) {
      if (arr[i][j] && !d[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) cnt++;
  }
  if (cnt > ans) ans = cnt;
}

void dfs(int dep, int cnt) {
  if (cnt == K) {
    check();
    return;
  }
  if (dep == 26 || cnt > K) {
    return;
  }
  dfs(dep + 1, cnt);
  if (!d[dep]) {
    d[dep] = 1;
    dfs(dep + 1, cnt + 1);
    d[dep] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    string tmp; cin >> tmp;
    for (int j = 0; j < tmp.size(); j++) {
      arr[i][tmp[j] - 'a'] = 1;
    }
  }
  d['a' - 'a'] = 1;
  d['n' - 'a'] = 1;
  d['t' - 'a'] = 1;
  d['i' - 'a'] = 1;
  d['c' - 'a'] = 1;
  dfs(0, 5);
  cout << ans << '\n';
}