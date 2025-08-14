// https://www.acmicpc.net/problem/25345
#include <iostream>
using namespace std;
long long cnt, MOD =  1e9 + 7, N, K, d[2001][2001], com;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    long long tmp; cin >> tmp;
  }
  for (int i = 1; i <= N; i++)
    d[i][1] = 1;
  for (int j = 2; j <= K; j++)
    for (int i = j; i <= N; i++)
      d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % MOD;
  for (int i = 1; i <= N; i++) com += d[i][K];
  for (int i = 1; i < K; i++) {
    com *= 2;
    com %= MOD;
  }
  cout << com << '\n';
}