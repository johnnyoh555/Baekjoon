// https://www.acmicpc.net/problem/28706
#include <iostream>
using namespace std;
int N, T, b, d;
char a, c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    bool dp[7] = {};
    dp[1] = 1;
    for (int n = 0; n < N; n++) {
      cin >> a >> b >> c >> d;
      bool tmp[7] = {};
      for (int i = 0; i < 7; i++) {
        if (!dp[i]) continue;
        if (a == '+') tmp[((i + b) % 7)] = 1;
        else tmp[((i * b) % 7)] = 1;
        if (c == '+') tmp[((i + d) % 7)] = 1;
        else tmp[((i * d) % 7)] = 1;
      }
      for (int i = 0; i < 7; i++) dp[i] = tmp[i];
    }
    cout << (dp[0] == 1 ? "LUCKY\n" : "UNLUCKY\n");
  }
}