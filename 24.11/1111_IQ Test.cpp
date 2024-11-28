// https://www.acmicpc.net/problem/1111
#include <iostream>
using namespace std;
int N, arr[50], cnt, ans = 2e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int a = -200; a <= 200; a++) {
    if (N == 1) {cnt = 2; break;}
    int b = arr[1] - arr[0] * a;
    bool flag = 0;
    for (int i = 1; i < N - 1; i++) {
      if (arr[i] * a + b != arr[i + 1]) {flag = 1; break;}
    }
    if (!flag) {
      if (ans != arr[N - 1] * a + b) cnt++;
      ans = arr[N - 1] * a + b;
    }
  }
  if (!cnt) cout << "B\n";
  else if (cnt == 1) cout << ans << '\n';
  else cout << "A\n";
}