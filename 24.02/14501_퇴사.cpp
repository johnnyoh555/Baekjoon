// https://www.acmicpc.net/problem/14501

#include <iostream>

using namespace std;

int T[16];
int P[16];
int vis[16];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> T[i] >> P[i];
  }
  for (int i = N; i >= 1; i--) {
    if (i + T[i] - 1 > N) continue;
    int max = 0;
    for (int j = i + T[i]; j <= N; j++) {
      if (vis[j] > max) max = vis[j];
    }
    vis[i] = P[i] + max;
  }
  int max = 0;
  for (int i = 1; i <= N; i++) {
    if (vis[i] > max) max = vis[i];
  }
  cout << max << '\n';
}