// https://www.acmicpc.net/problem/23888
#include <iostream>
using namespace std;
long a, d, q, c, l, r, arr[1000001];

long gdb(long x, long y)
{
    long z = x % y;
    if (z == 0) return y;
    return gdb(y, z);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> d >> q;
  for (long i = 2; i <= 1000001; i++) arr[i] = i - 1 + arr[i - 1];
  for (long i = 0; i < q; i++) {
    cin >> c >> l >> r;
    if (c == 1) {
      cout << a * (r - l + 1) + d * (arr[r] - arr[l - 1]) << '\n';
    } else {
      cout << gdb(a + d * (l == r ? l - 1 : l), a + d * (l - 1)) << '\n';
    }
  }
}