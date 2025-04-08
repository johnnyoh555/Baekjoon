// https://www.acmicpc.net/problem/20166
#include <iostream>
#include <unordered_map>
using namespace std;
int N, M, K, board[11][11], cnt, dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
unordered_map<string, int> um;
string str;

void bfs(int y, int x, int dep) {
  if (dep == str.size() - 1) {
    cnt++;
    return;
  }
  for (int dir = 0; dir < 8; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0) nx = M - 1;
    if (ny < 0) ny = N - 1;
    if (nx >= M) nx = 0;
    if (ny >= N) ny = 0;
    if (board[ny][nx] != str[dep + 1]) continue;
    bfs(ny, nx, dep + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    string tmp; cin >> tmp;
    for (int j = 0; j < M; j++) {
      board[i][j] = tmp[j];
    }
  }
  for (int i = 0; i < K; i++) {
    cin >> str; cnt = 0;
    if (um.find(str) == um.end()) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (board[i][j] != str[0]) continue;
          bfs(i, j, 0);
        }
      }
      um[str] = cnt;
    }
    cout << um[str] << '\n';
  }
}