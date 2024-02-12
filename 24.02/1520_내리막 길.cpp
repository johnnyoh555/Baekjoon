// https://www.acmicpc.net/problem/1520

#include <iostream>

using namespace std;
int M, N;

int d[502][502];
int vis[502][502];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dfs(int i, int j) {
  if (i == M && j == N) return 1;
  if (vis[i][j] != -1) return vis[i][j];
  vis[i][j] = 0;
  for (int dir = 0; dir < 4; dir++) {
    int nx = j + dx[dir];
    int ny = i + dy[dir];
    if (ny < 1 || nx < 1 || ny > M || nx > N) continue;
    if (d[ny][nx] < d[i][j]) {
      vis[i][j] += dfs(ny, nx);
    }
  }
  return vis[i][j];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> d[i][j];
      vis[i][j] = -1;
    }
  }
  cout << dfs(1, 1) << '\n';
}