// https://www.acmicpc.net/problem/9084

#include <iostream>

using namespace std;

int coin[21];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T, N, M;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    for (int j = 1; j <= N; j++) {
      cin >> coin[j];
    }
    cin >> M;
    long d[10001] = {
        0,
    };
    d[0] = 1;
    for (int j = 1; j <= N; j++) {
      for (int k = coin[j]; k <= M; k++) {
        d[k] += d[k - coin[j]];
      }
    }
    cout << d[M] << '\n';
  }
}