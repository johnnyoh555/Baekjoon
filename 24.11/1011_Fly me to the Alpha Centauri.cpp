// https://www.acmicpc.net/problem/1011
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long T;
  cin >> T;
  while (T--) {
    long x, y, sum = 0, ans = 0;
    cin >> x >> y;
    while (sum < y - x)
      sum += ans++ / 2 + 1;
    cout << ans << '\n';
  }
}
