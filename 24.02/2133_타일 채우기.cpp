// https://www.acmicpc.net/problem/2133

#include <iostream>

using namespace std;

int d[31];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  if (N % 2 == 1) {
    cout << "0\n";
    return (0);
  }
  d[0] = 1;
  d[2] = 3;
  for (int i = 2; i <= N / 2; i++) {
    d[i * 2] += d[i * 2 - 2] * 3;
    for (int j = 2; i * 2 - j * 2 >= 0; j++) {
      d[i * 2] += d[i * 2 - j * 2] * 2;
    }
  }
  cout << d[N] << '\n';
}