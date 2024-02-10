// https://www.acmicpc.net/problem/15486

#include <iostream>

using namespace std;

int T[1500001];
int P[1500001];
int vis[1500001];

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
    int j = i + T[i];
    int e = j + T[j];
    for (; j <= N && j < e; j++) {
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