// https://www.acmicpc.net/problem/10971
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, board[16][16], dp[16][1 << 16], INF = 987654321;

int dfs(int cur, int vis) {
  if (vis == (1 << N) - 1) {
    if (board[cur][0] == 0)
      return INF;
    return board[cur][0];
  }

  if (dp[cur][vis] != -1)
    return dp[cur][vis];

  dp[cur][vis] = INF;

  for (int i = 0; i < N; i++) {
    if (board[cur][i] == 0) continue;
    if ((vis & (1 << i)) == (1 << i)) continue;
    dp[cur][vis] = min(dp[cur][vis], board[cur][i] + dfs(i, vis | 1 << i));
  }

  return dp[cur][vis];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> board[i][j];
  
  memset(dp, -1, sizeof(dp));

  cout << dfs(0, 1) << '\n';
}