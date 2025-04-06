// https://www.acmicpc.net/problem/1322
#include <iostream>
#include <bitset>
using namespace std;
long long X, K, idx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> X >> K;
  bitset<64> a(X), b(K);
  for (int i = 0; i < 64; i++) {
    if (a[i] == 1) {
      a[i] = 0;
    } else {
      a[i] = b[idx];
      idx++;
    }
  }
  cout << a.to_ullong() << '\n';
}