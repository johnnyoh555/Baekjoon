// https://www.acmicpc.net/problem/2666
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, X, Y, M, arr[20], ans = 2e9 + 1;

void dfs(int s, int e, int sum, int dep) {
  if (dep == M) {
    if (ans > sum) ans = sum;
    return;
  }
  if (arr[dep] < e) dfs(arr[dep], e, sum + abs(arr[dep] - s), dep + 1);
  if (arr[dep] > s) dfs(s, arr[dep], sum + abs(arr[dep] - e), dep + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> X >> Y >> M;
  if (Y < X) swap(X, Y);
  for (int i = 0; i < M; i++) cin >> arr[i];
  dfs(X, Y, 0, 0);
  cout << ans << '\n';
}