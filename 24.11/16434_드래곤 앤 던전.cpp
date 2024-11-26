// https://www.acmicpc.net/problem/16434
#include <iostream>
using namespace std;
long long st, en = 2e16 + 1, mid, N, atk, arr[123456][3], ans = 2e16;

bool ft(long long x) {
  long long p = atk;
  long long hp = x;
  for (int i = 0; i < N; i++) {
    if (arr[i][0] == 1) {
      long long sum = arr[i][2] / p;
      if (!(arr[i][2] % p)) sum--;
      hp -= arr[i][1] * sum;
    } else {
      p += arr[i][1];
      hp += arr[i][2];
    }
    if (hp > x) hp = x;
    if (hp <= 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> atk;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 3; j++)
      cin >> arr[i][j];

  while (st < en) {
    mid = (st + en) / 2;
    if (ft(mid)) {
      en = mid;
      if (ans > mid ) ans = mid;
    } else {
      st = mid + 1;
    }
  }
  cout << ans << '\n';
}