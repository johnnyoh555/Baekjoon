// https://www.acmicpc.net/problem/1300
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, ans, st, en, mid, cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  st = 1, en = K;
  while (st <= en) {
    mid = (st + en) / 2;
    cnt = 0;
    for (int i = 1; i <= N; i++) cnt += min(mid / i, N);
    if (cnt < K) st = mid + 1;
    else {
      ans = mid;
      en = mid - 1;
    }
  }
  cout << ans << '\n';
}