// https://www.acmicpc.net/problem/1509
#include <iostream>
#include <algorithm>
using namespace std;
string str;
bool pelin[2502][2502];
int dp[2502];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; i + j < str.size(); j++) {
      if (str[j] == str[j + i]) {
        if (i <= 1) pelin[j][j + i] = 1;
        else pelin[j][j + i] = pelin[j + 1][j + i - 1];
      }
    }
  }
  fill(dp + 1, dp + str.size() + 1, 2e9);
  for (int i = 0; i < str.size(); i++) {
    for (int j = i; j < str.size(); j++) {
      if (!pelin[i][j]) continue;
      dp[j + 1] = min(dp[j + 1], dp[i] + 1);
    }
  }
  cout << dp[str.size()] << '\n';
}
