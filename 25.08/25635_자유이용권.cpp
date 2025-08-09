// https://www.acmicpc.net/problem/25635
#include <iostream>
using namespace std;
long long N, sum, mx, tmp;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    sum += tmp;
    if (mx < tmp) mx = tmp;
  }
  sum -= mx;
  cout << (sum < mx ? sum * 2 + 1 : sum + mx) << '\n';
}