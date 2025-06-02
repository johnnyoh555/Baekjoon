// https://www.acmicpc.net/problem/11437
#include <iostream>
#include <vector>
using namespace std;
int N, M, p[50001][2];
vector<int> v[50001];

int ft(int a, int b) {
  while (p[a][1] > p[b][1]) a = p[a][0];
  while (p[a][1] < p[b][1]) b = p[b][0];
  while (a != b) {
    a = p[a][0];
    b = p[b][0];
  }
  return a;
}

void dfs(int parent, int x, int dep) {
  p[x][0] = parent;
  p[x][1] = dep;
  for (int nxt : v[x]) {
    if (p[nxt][1]) continue;
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
  cin >> M;
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    cout << ft(a, b) << '\n';
  }
}