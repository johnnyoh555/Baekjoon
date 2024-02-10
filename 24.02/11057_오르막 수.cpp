// https://www.acmicpc.net/problem/11057

#include <iostream>

using namespace std;

long d[1001][10];
int mod = 10007;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i <= 9; i++) {
    d[1][i] = 1;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= j; k++) d[i][j] += d[i - 1][k] % mod;
    }
  }
  int sum = 0;
  for (int i = 0; i <= 9; i++) {
    sum += d[N][i];
  }
  cout << sum % mod << '\n';
}