// https://www.acmicpc.net/problem/9252
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];
string N, M;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N.size(); i++) {
    for (int j = 1; j <= M.size(); j++) {
      if (N[i - 1] == M[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
  }

  string str;
  int a = N.size(), b = M.size();
  while (a && b) {
    if (dp[a][b] == dp[a - 1][b]) {
      a--;
    } else if (dp[a][b] == dp[a][b - 1]) {
      b--;
    } else {
      str.push_back(N[a - 1]);
      a--;
      b--;
    }
  }
  reverse(str.begin(), str.end());
  cout << str.size() << '\n';
  if (str.size()) cout << str << '\n';
}