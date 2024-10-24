// https://www.acmicpc.net/problem/10253
#include <iostream>
using namespace std;

long gcd(long a, long b) {
  return a % b ? gcd(b, a % b) : b;
}

long ft(long a, long b) {
  int i = 1, GCD;
  while (a != 1) {
    long r = (b % a == 0) ? b / a : b / a + 1;
    a = a * r - b;
    b = b * r;
    GCD = gcd(a, b);
    a /= GCD; b /= GCD;
  }
  return b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    long a, b; cin >> a >> b;
    cout << ft(a, b) << '\n';
  }
}