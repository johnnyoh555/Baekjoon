// https://www.acmicpc.net/problem/34137
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long tree[200001 * 4], arr[200001], N, M, T, K, ans[200001], lazy[200001 * 4];
vector<tuple<int, int, int, int>> v;

void updateLazy(int node, int l, int r) {
  if (!lazy[node]) return;
  tree[node] = lazy[node] * (r - l + 1);
  if (l != r) {
    lazy[node * 2] = lazy[node];
    lazy[node * 2 + 1] = lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int l, int r, int st, int en, int row, int color) {
  updateLazy(node, l, r);
  if (st > r || en < l) return;
  if (st <= l && r <= en) {
    ans[color] += (N + 1 - row) * (r - l + 1) - tree[node];
    tree[node] = (N + 1 - row) * (r - l + 1);
    if (l != r) {
      lazy[node * 2] = (N + 1 - row);
      lazy[node * 2 + 1] = (N + 1 - row);
    }
    return;
  }
  int mid = (l + r) / 2;
  update(node * 2, l, mid, st, en, row, color);
  update(node * 2 + 1, mid + 1, r, st, en, row, color);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M >> T >> K;
  for (int i = 1; i <= M; i++) {
    int tmp; cin >> tmp;
    v.push_back({1, i, i, tmp});
  }
  for (int i = 0; i < K; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    v.push_back({a, b, c, d});
  }
  sort(v.begin(), v.end(), greater());
  for (int i = 0; i < v.size(); i++) {
    auto [a, b, c, d] = v[i];
    update(1, 1, M, b, c, a, d);
  }
  for (int i = 1; i <= T; i++) cout << ans[i] << (i == T ? '\n' : ' ');
}