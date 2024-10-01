// https://www.acmicpc.net/problem/2624
#include <iostream>
#include <vector>
using namespace std;
long T, k, dp[10001];
vector<pair<int, int> > v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b; cin >> a >> b;
    v.push_back({a, b});
  }
  dp[0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = T; j >= 1; j--) {
      for (int m = 1; m <= v[i].second; m++) {
        if (j - m * v[i].first < 0) continue;
        dp[j] += dp[j - m * v[i].first];
      }
    }
  }
  cout << dp[T] << '\n';
}