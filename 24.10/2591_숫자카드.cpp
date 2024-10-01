// https://www.acmicpc.net/problem/2591
#include <iostream>
using namespace std;
string str;
int dp[41];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  dp[0] = 1;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != '0') dp[i + 1] += dp[i];
    if (i > 0) {
      int tmp = (str[i - 1] - '0') * 10 + str[i] - '0';
      if (tmp >= 10 && tmp <= 34) dp[i + 1] += dp[i - 1];
    }
  }
  cout << dp[str.size()] << '\n';
}