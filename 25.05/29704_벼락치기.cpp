// https://www.acmicpc.net/problem/29704
#include <iostream>
#include <algorithm>
using namespace std;
int N, T, sum, dp[1001], days, fine;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> T;
  for (int i = 0; i < N; i++) {
    cin >> days >> fine;
    sum += fine;
    for (int j = T; j >= days; j--)
      dp[j] = max(dp[j], dp[j - days] + fine);
  }
  cout << sum - dp[T] << '\n';
}