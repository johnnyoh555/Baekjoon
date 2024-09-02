// https://www.acmicpc.net/problem/14267
#include <iostream>
#include <vector>
using namespace std;
int n, m, save[100001], ans[100001];
vector<int> v[100001];

void tree(int node, int sum) {
  sum += save[node];
  ans[node] = sum;
  for (auto nxt : v[node]) tree(nxt, sum);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int tmp; cin >> tmp;
    if (tmp == -1) continue;
    v[tmp].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    save[a] += b;
  }
  tree(1, 0);
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';
}