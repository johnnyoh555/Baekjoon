// https://www.acmicpc.net/problem/2602
#include <iostream>
using namespace std;
string b[2], str;
long dp[2][21][101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str >> b[0] >> b[1];
  int ss = str.size(), bb = b[0].size();
  for (int i = 0; i < bb; i++) {dp[0][0][i] = 1; dp[1][0][i] = 1;}
  for (int i = 0; i < ss; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < bb; k++) {
        if (b[j][k] == str[i]) dp[j][i + 1][k + 1] += dp[(j + 1) % 2][i][k];
        dp[j][i + 1][k + 1] += dp[j][i + 1][k];
      }
  cout << dp[0][ss][bb] + dp[1][ss][bb] << '\n';
}