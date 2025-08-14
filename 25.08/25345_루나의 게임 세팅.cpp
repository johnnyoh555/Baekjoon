// https://www.acmicpc.net/problem/25345
#include <iostream>
using namespace std;
long long M = 1e9 + 7, N, K, d[2001][2001], a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> a;
  for (int i = 0; i <= N; i++) d[i][0] = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++)
      d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % M;
  for (int i = 1; i < K; i++) {d[N][K] *= 2; d[N][K] %= M;}
  cout << d[N][K] << '\n';
}