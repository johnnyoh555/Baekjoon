// https://www.acmicpc.net/problem/11438
#include <iostream>
#include <vector>
using namespace std;
int N, M, p[100001][18], d[100001];
vector<int> v[100001];

int ft(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  if (d[a] != d[b]) {
    int dif = d[a] - d[b];
    for (int i = 0; dif > 0; i++) {
      if (dif % 2 == 1) a = p[a][i];
      dif = dif >> 1;
    }
  }

  if (a != b) {
    for (int k = 17; k >= 0; k--) {
      if (p[a][k] != 0 && p[a][k] != p[b][k]) {
        a = p[a][k];
        b = p[b][k];
      }
    }
    a = p[a][0];
  }

  return a;
}

void dfs(int parent, int x, int dep) {
  p[x][0] = parent;
  d[x] = dep;
  for (int nxt : v[x]) {
    if (nxt == parent) continue;
    dfs(x, nxt, dep + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(0, 1, 1);

  for (int k = 1; k < 18; k++)
    for (int idx = 2; idx <= N; idx++)
      if (p[idx][k - 1]) p[idx][k] = p[p[idx][k - 1]][k - 1];

  cin >> M;
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    cout << ft(a, b) << '\n';
  }
}