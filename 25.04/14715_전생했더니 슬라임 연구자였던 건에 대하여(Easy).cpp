// https://www.acmicpc.net/problem/14715
#include <iostream>
using namespace std;
int K, cnt, ans, idx = 2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K;
  while (idx <= K && K > 1) {
    if (K % idx == 0) {
      K /= idx;
      cnt++;
    } else {
      idx++;
    }
  }
  while (cnt > 1) {
    cnt = (cnt + 1) / 2;
    ans++;
  }
  cout << ans << '\n';
}