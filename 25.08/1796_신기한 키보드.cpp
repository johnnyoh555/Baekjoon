// https://www.acmicpc.net/problem/1796
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string str;
vector<int> v[26];
int ans = 2e9;

void dfs(int idx, int dep, int sum) {
  if (dep == 26) {
    if (sum < ans) ans = sum;
    return;
  }
  if (v[dep].empty()) {
    dfs(idx, dep + 1, sum);
  } else {
    int l = v[dep][0], r = v[dep][v[dep].size() - 1];
    dfs(l, dep + 1, sum + (r - l) + abs(r - idx) + v[dep].size());
    dfs(r, dep + 1, sum + (r - l) + abs(l - idx) + v[dep].size());
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    v[str[i] - 'a'].push_back(i);
  }
  dfs(0, 0, 0);
  cout << ans << '\n';
}