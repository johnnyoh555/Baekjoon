// https://www.acmicpc.net/problem/5557
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll N, arr[100];
vector<ll> dp(21);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  dp[arr[0]] = 1;
  for (int i = 1; i < N - 1; i++) {
    vector<ll> tmp(21);
    for (int j = 0; j < 21; j++) {
      if (!dp[j]) continue;
      if (j + arr[i] < 21) tmp[j + arr[i]] += dp[j];
      if (j - arr[i] >= 0) tmp[j - arr[i]] += dp[j];
    }
    dp.swap(tmp);
  }
  cout << dp[arr[N - 1]] << '\n';
}