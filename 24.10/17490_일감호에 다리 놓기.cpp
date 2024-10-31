// https://www.acmicpc.net/problem/17490
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long N, M, K, arr[1000001];
vector<pair<long, long>> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 0; i < M; i++) {
    long a, b; cin >> a >> b;
    if ((a == N && b == 1) || (a == 1 && b == N)) v.push_back({N, 1});
    else if (a < b) v.push_back({a, b});
    else v.push_back({b, a});
  }
  if (M < 2) {cout << "YES\n"; return 0;}
  sort(v.begin(), v.end());
  long st = v[0].second, en = v[0].first, mn = 2e9, idx = 1, sum = 0;
  while (true) {
    if (arr[st] < mn) mn = arr[st];
    if (idx < v.size() && st == v[idx].first) {
      sum += mn;
      mn = 2e9;
      idx++;
    }
    if (st == en) {sum += mn; break;}
    if (st == N) st = 1;
    else st++;
  }
  if (sum <= K) cout << "YES\n";
  else cout << "NO\n";
}