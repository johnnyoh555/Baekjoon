// https://www.acmicpc.net/problem/10835
#include <iostream>
#include <algorithm>
using namespace std;
int N, a[2001], b[2001], dp[2001][2001];

int ft(int y, int x) {
  if (y == N || x == N) return 0;
  else if (dp[y][x] != -1) return dp[y][x];

  if (a[y] > b[x]) return dp[y][x] = b[x] + ft(y, x + 1);
  else return dp[y][x] = max(ft(y + 1, x), ft(y + 1, x + 1));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];
  for (int i = 0; i < N; i++) fill(dp[i], dp[i] + N, -1);
  cout << ft(0, 0) << '\n';
}