// https://www.acmicpc.net/problem/11055

#include <iostream>

using namespace std;

long d[1001];
long vis[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> d[i];
  }

  for (int i = 1; i <= N; i++) {
    int max = 0;
    for (int j = 1; j < i; j++) {
      if (d[j] < d[i] && vis[j] > max) {
        max = vis[j];
      }
    }
    vis[i] = max + d[i];
  }
  int max = 0;
  for (int i = 1; i <= N; i++) {
    if (vis[i] > max) max = vis[i];
  }
  cout << max << '\n';
}
