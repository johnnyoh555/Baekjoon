// https://www.acmicpc.net/problem/2568
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> dp;
vector<pair<int, int>> v;
int N, d[500001], arr[500001];
bool b[500001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    auto it = lower_bound(dp.begin(), dp.end(), v[i].second);
    if (it == dp.end()) {
      dp.push_back(v[i].second);
      arr[dp.size()] = v[i].first;
      d[v[i].first] = arr[dp.size() - 1];
    } else {
      dp[it - dp.begin()] = v[i].second;
      arr[it - dp.begin() + 1] = v[i].first;
      d[v[i].first] = arr[it - dp.begin()];
    }
  }
  int x = arr[dp.size()];
  while (x) {b[x] = 1; x = d[x];}
  cout << N - dp.size() << '\n';
  for (int i = 0; i < v.size(); i++)
    if (!b[v[i].first]) cout << v[i].first << '\n';
}