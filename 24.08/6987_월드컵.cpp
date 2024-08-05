// https://www.acmicpc.net/problem/6987
#include <iostream>
#include <algorithm>
using namespace std;
int score[4][18], ans, arr[18];

void dfs(int A, int B, int x) {
  if (B == 6) {
    A++;
    B = A + 1;
  }
  if (A == 5 || ans == 1) {
    if (!ans && equal(score[x], score[x] + 18, arr)) ans = 1;
    return;
  }

  arr[A * 3]++;
  arr[B * 3 + 2]++;
  dfs(A, B + 1, x);
  arr[A * 3]--;
  arr[B * 3 + 2]--;

  arr[A * 3 + 1]++;
  arr[B * 3 + 1]++;
  dfs(A, B + 1, x);
  arr[A * 3 + 1]--;
  arr[B * 3 + 1]--;

  arr[A * 3 + 2]++;
  arr[B * 3]++;
  dfs(A, B + 1, x);
  arr[A * 3 + 2]--;
  arr[B * 3]--;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 18; j++)
      cin >> score[i][j];
  
  for (int i = 0; i < 4; i++) {
    ans = 0;
    fill(arr, arr + 18, 0);
    dfs(0, 1, i);
    cout << ans << ' ';
  }
  cout << '\n';
}