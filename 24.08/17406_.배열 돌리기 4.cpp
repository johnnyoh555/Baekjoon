// https://www.acmicpc.net/problem/17406
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int N, M, K, board[51][51], board2[51][51], tmp[51][51], ans = 2e9 + 1;
vector<tuple<int, int, int> > v;

void ftr(int r, int c, int s) {
  tmp[r][c] = board2[r][c];
  for (int i = 1; i <= s; i++) {
    for (int j = c + i; j > c - i; j--)
      tmp[r - i][j] = board2[r - i][j - 1];
    for (int j = r + i; j > r - i; j--)
      tmp[j][c + i] = board2[j - 1][c + i];
    for (int j = c - i; j < c + i; j++)
      tmp[r + i][j] = board2[r + i][j + 1];
    for (int j = r - i; j < r + i; j++)
      tmp[j][c - i] = board2[j + 1][c - i]; 
  }
  for (int i = r - s; i <= r + s; i++)
    for (int j = c - s; j <= c + s; j++)
      board2[i][j] = tmp[i][j];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      cin >> board[i][j];
  for (int i = 0; i < K; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back({a, b, c});
  }
  vector<int> arr;
  for (int i = 0; i < K; i++) arr.push_back(i);
  do {
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++)
        board2[i][j] = board[i][j];
    for (int i = 0; i < arr.size(); i++) {
      int a, b, c;
      tie(a, b, c) = v[arr[i]];
      ftr(a, b, c);
    }
    for (int i = 1; i <= N; i++) {
      int sum = 0;
      for (int j = 1; j <= M; j++) sum += board2[i][j];
      if (ans > sum) ans = sum;
    }
  } while (next_permutation(arr.begin(), arr.end()));
  cout << ans << '\n';
}
