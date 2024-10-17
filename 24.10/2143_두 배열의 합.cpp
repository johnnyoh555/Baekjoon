// https://www.acmicpc.net/problem/2143
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long n, m, T, A[1001], B[1001], ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T >> n;
  for (int i = 1; i <= n; i++) {cin >> A[i]; A[i] += A[i - 1];}
  cin >> m;
  for (int i = 1; i <= m; i++) {cin >> B[i]; B[i] += B[i - 1];}
  vector<long> v;
  for (int i = 1; i <= m; i++)
    for (int j = i; j <= m; j++)
      v.push_back(B[j] - B[i - 1]);
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      long tmp = T - (A[j] - A[i - 1]);
      ans += upper_bound(v.begin(), v.end(), tmp) - lower_bound(v.begin(), v.end(), tmp);
    }
  cout << ans << '\n';
}