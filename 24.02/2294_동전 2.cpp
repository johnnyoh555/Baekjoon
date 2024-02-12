// https://www.acmicpc.net/problem/2294

#include <iostream>

using namespace std;

short coin[101];
unsigned int d[10001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  d[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> coin[i];
    if (coin[i] <= k) d[coin[i]] = 1;
  }
  for (int i = 1; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      if (i + coin[j] > k) continue;
      if (!d[i]) continue;
      if (!d[i + coin[j]])
        d[i + coin[j]] = d[i] + 1;
      else
        d[i + coin[j]] = min(d[i] + 1, d[i + coin[j]]);
    }
  }
  if (!d[k])
    cout << "-1\n";
  else
    cout << d[k] << '\n';
}