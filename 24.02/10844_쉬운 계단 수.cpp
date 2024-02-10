// https://www.acmicpc.net/problem/10844

#include <iostream>

using namespace std;

long d[101][10];
int mod = 1000000000;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 1; i < 10; i++) {
    d[1][i] = 1;
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      if (j != 0) d[i][j] += (d[i - 1][j - 1] + d[i][j]) % mod;
      if (j != 9) d[i][j] = (d[i - 1][j + 1] + d[i][j]) % mod;
    }
  }
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += d[N][i];
  }
  cout << sum % mod << '\n';
}