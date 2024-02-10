// https://www.acmicpc.net/problem/9461

#include <iostream>

using namespace std;

long d[101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  d[1] = 1;
  d[2] = 1;
  d[3] = 1;
  d[4] = 2;
  d[5] = 2;
  for (int i = 6; i <= 100; i++) {
    d[i] = d[i - 1] + d[i - 5];
  }
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    cout << d[N] << '\n';
  }
}