// https://www.acmicpc.net/problem/1516
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, dp[501], arr[501];
vector<int> v[501];

int ft(int x) {
  if (!v[x].size()) dp[x] = arr[x];
  if (dp[x]) return dp[x];
  for (auto nxt : v[x])
    dp[x] = max(dp[x], ft(nxt) + arr[x]);
  return dp[x];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    while (true) {
      int tmp; cin >> tmp;
      if (tmp == -1) break;
      v[i].push_back({tmp});
    }
  }
  for (int i = 1; i <= N; i++)
    cout << ft(i) << '\n';
}