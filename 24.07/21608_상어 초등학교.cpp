// https://www.acmicpc.net/problem/21608
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, map[22][22], ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> v[402], o;

void check(int y, int x) {
  int score = 0;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
    if (find(v[map[y][x]].begin(), v[map[y][x]].end(), map[ny][nx]) != v[map[y][x]].end()) score++;
  }
  if (score == 1) ans += 1;
  else if (score == 2) ans += 10;
  else if (score == 3) ans += 100;
  else if (score == 4) ans += 1000;
}

void mapping(int z) {
  int x, y, fcnt = -1, ecnt = -1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (map[i][j]) continue;
      int etmp = 0, ftmp = 0;
      for (int dir = 0; dir < 4; dir++) {
        int nx = j + dx[dir];
        int ny = i + dy[dir];
        if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
        if (!map[ny][nx]) etmp++;
        else if (find(v[z].begin(), v[z].end(), map[ny][nx]) != v[z].end()) ftmp++;
      }
      if (ftmp > fcnt || (ftmp == fcnt && etmp > ecnt)) {
        fcnt = ftmp;
        ecnt = etmp;
        y = i;
        x = j;
      } 
    }
  }
  map[y][x] = z;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N * N; i++) {
    int a; cin >> a;
    o.push_back(a);
    for (int j = 0; j < 4; j++) {
      int b; cin >> b;
      v[a].push_back(b);
    }
  }
  for (int i = 0; i < o.size(); i++) {
    mapping(o[i]);
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      check(i, j);
    }
  }
  cout << ans << '\n';
}