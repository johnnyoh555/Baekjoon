// https://www.acmicpc.net/problem/20057
#include <iostream>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, map[500][500], x, y, dir, ans;
bool vis[500][500];

void up(int y, int x) {
  int per = 0;
  if (!(x + 1 > N || y + 1 > N)) map[y + 1][x + 1] += map[y][x] * 0.01; per += map[y][x] * 0.01;
  if (!(x + 1 > N)) map[y][x + 1] += map[y][x] * 0.07; per += map[y][x] * 0.07;
  if (!(x + 2 > N)) map[y][x + 2] += map[y][x] * 0.02; per += map[y][x] * 0.02;
  if (!(y - 1 < 1 || x + 1 > N)) map[y - 1][x + 1] += map[y][x] * 0.10; per += map[y][x] * 0.10;
  if (!(y - 2 < 1)) map[y - 2][x] += map[y][x] * 0.05; per += map[y][x] * 0.05;
  if (!(y - 1 < 1 || x - 1 < 1)) map[y - 1][x - 1] += map[y][x] * 0.10; per += map[y][x] * 0.10;
  if (!(x - 1 < 1)) map[y][x - 1] += map[y][x] * 0.07; per += map[y][x] * 0.07;
  if (!(x - 2 < 1)) map[y][x - 2] += map[y][x] * 0.02; per += map[y][x] * 0.02;
  if (!(y + 1 > N || x - 1 < 1)) map[y + 1][x - 1] += map[y][x] * 0.01; per += map[y][x] * 0.01;
  if (!(y - 1 < 1)) map[y - 1][x] += map[y][x] - per;

  map[y][x] = 0;
}

void down(int y, int x) {
  int per = 0;
  if (!(x - 1 < 1 || y - 1 < 1)) map[y - 1][x - 1] += map[y][x] * 0.01; per += map[y][x] * 0.01;
  if (!(x - 1 < 1)) map[y][x - 1] += map[y][x] * 0.07; per += map[y][x] * 0.07;
  if (!(x - 2 < 1)) map[y][x - 2] += map[y][x] * 0.02; per += map[y][x] * 0.02;
  if (!(y + 1 > N || x - 1 < 1)) map[y + 1][x - 1] += map[y][x] * 0.1; per += map[y][x] * 0.1;
  if (!(y + 2 > N)) map[y + 2][x] += map[y][x] * 0.05; per += map[y][x] * 0.05;
  if (!(y + 1 > N || x + 1 > N)) map[y + 1][x + 1] += map[y][x] * 0.1; per += map[y][x] * 0.1;
  if (!(x + 1 > N)) map[y][x + 1] += map[y][x] * 0.07; per += map[y][x] * 0.07;
  if (!(x + 2 > N)) map[y][x + 2] += map[y][x] * 0.02; per += map[y][x] * 0.02;
  if (!(y - 1 < 1 || x + 1 > N)) map[y - 1][x + 1] += map[y][x] * 0.01; per += map[y][x] * 0.01;
  if (!(y + 1 > N)) map[y + 1][x] += map[y][x] - per;

  map[y][x] = 0;
}

void left(int y, int x) {
  int per = 0;
  if (!(y - 1 < 1 || x + 1 > N)) map[y - 1][x + 1] += map[y][x] * 0.01; per += map[y][x] * 0.01;
  if (!(y - 1 < 1)) map[y - 1][x] += map[y][x] * 0.07; per += map[y][x] * 0.07;
  if (!(y - 2 < 1)) map[y - 2][x] += map[y][x] * 0.02; per += map[y][x] * 0.02;
  if (!(y - 1 < 1 || x - 1 < 1)) map[y - 1][x - 1] += map[y][x] * 0.1; per += map[y][x] * 0.1;
  if (!(x - 2 < 1)) map[y][x - 2] += map[y][x] * 0.05; per += map[y][x] * 0.05;
  if (!(y + 1 > N || x - 1 < 1)) map[y + 1][x - 1] += map[y][x] * 0.1; per += map[y][x] * 0.1;
  if (!(y + 1 > N)) map[y + 1][x] += map[y][x] * 0.07; per += map[y][x] * 0.07;
  if (!(y + 2 > N)) map[y + 2][x] += map[y][x] * 0.02; per += map[y][x] * 0.02;
  if (!(y + 1 > N || x + 1 > N)) map[y + 1][x + 1] += map[y][x] * 0.01; per += map[y][x] * 0.01;
  if (!(x - 1 < 1)) map[y][x - 1] += map[y][x] - per;
  
  map[y][x] = 0;
}

void right(int y, int x) {
  int per = 0;
  if (!(y + 1 > N || x - 1 < 1)) map[y + 1][x - 1] += map[y][x] * 0.01; per += map[y][x] * 0.01;
  if (!(y + 1 > N)) map[y + 1][x] += map[y][x] * 0.07; per += map[y][x] * 0.07;
  if (!(y + 2 > N)) map[y + 2][x] += map[y][x] * 0.02; per += map[y][x] * 0.02;
  if (!(y + 1 > N || x + 1 > N)) map[y + 1][x + 1] += map[y][x] * 0.1; per += map[y][x] * 0.1;
  if (!(x + 2 > N)) map[y][x + 2] += map[y][x] * 0.05; per += map[y][x] * 0.05;
  if (!(y - 1 < 1 || x + 1 > N)) map[y - 1][x + 1] += map[y][x] * 0.1 ; per += map[y][x] * 0.1;
  if (!(y - 1 < 1)) map[y - 1][x] += map[y][x] * 0.07; per += map[y][x] * 0.07;
  if (!(y - 2 < 1)) map[y - 2][x] += map[y][x] * 0.02; per += map[y][x] * 0.02;
  if (!(y - 1 < 1 || x - 1 < 1)) map[y - 1][x - 1] += map[y][x] * 0.01; per += map[y][x] * 0.01;
  if (!(x + 1 > N)) map[y][x + 1] += map[y][x] - per;

  map[y][x] = 0;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> map[i][j];
      ans += map[i][j];
    }
  }
  x = N / 2 + 1; y = N / 2 + 1;
  vis[y][x] = 1;
  while (x != 1 || y != 1) {
    x += dx[dir];
    y += dy[dir];
    vis[y][x] = 1;
    if (dir == 0) {
      left(y, x);
      if (!vis[y + 1][x]) dir++;
    } else if (dir == 1) {
      down(y, x);
      if (!vis[y][x + 1]) dir++;
    } else if (dir == 2) {
      right(y, x);
      if (!vis[y - 1][x]) dir++;
    } else {
      up(y, x);
      if (!vis[y][x - 1]) dir = 0;
    }
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      ans -= map[i][j];

  cout << ans << '\n';
}