// https://www.acmicpc.net/problem/7579
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, ans, sum, bite[101], cost[101], dp[10001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> bite[i];
  for (int i = 0; i < N; i++) {cin >> cost[i]; sum += cost[i];}
  for (int i = 0; i < N; i++) 
    for (int j = sum; j >= cost[i]; j--)
      dp[j] = max(dp[j], dp[j - cost[i]] + bite[i]);
  for (int i = 0; i <= sum; i++) {
    if (dp[i] >= M) {
      cout << i;
      break;
    }
  }
}