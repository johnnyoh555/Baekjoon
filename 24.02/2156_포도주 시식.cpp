// https://www.acmicpc.net/problem/2156

#include <iostream>

using namespace std;

unsigned long d[10001];
unsigned long vis[10001][2];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> d[i];
  }
  vis[1][0] = d[1];
  vis[1][1] = d[1];
  vis[2][0] = d[2];
  vis[2][1] = d[2] + d[1];
  vis[3][0] = d[1] + d[3];
  vis[3][1] = d[2] + d[3];
  for (int i = 3; i <= N; i++) {
    vis[i][0] = d[i] + max(max(vis[i - 2][0], vis[i - 2][1]),
                           max(vis[i - 3][1], vis[i - 3][0]));
    vis[i][1] = d[i] + vis[i - 1][0];
  }
  if (N == 1) {
    cout << vis[1][0] << '\n';
    return 0;
  }
  cout << max(max(vis[N - 1][0], vis[N - 1][1]), max(vis[N][0], vis[N][1]))
       << '\n';
}