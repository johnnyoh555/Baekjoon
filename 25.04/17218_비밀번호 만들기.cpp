// https://www.acmicpc.net/problem/17218
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> s;
string A, B;
int dp[41][41], a, b;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;
  a = A.size();
  b = B.size();
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++) {
      if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  while (a && b) {
    if (A[a - 1] == B[b - 1]) {
      s.push(A[a - 1]);
      a--; b--;
    } else if (dp[a - 1][b] >= dp[a][b - 1]) a--;
    else b--;
  }
  while (!s.empty()) {cout << s.top(); s.pop();}
  cout << '\n';
}