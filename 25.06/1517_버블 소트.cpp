// https://www.acmicpc.net/problem/1517
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
long tree[2000001], N, ans;

int query(int node, int l, int r, int st, int en) {
  if (r < st || en < l) return 0;
  if (st <= l && r <= en) return tree[node];
  int mid = (l + r) / 2;
  return (query(node * 2, l, mid, st, en) + query(node * 2 + 1, mid + 1, r, st, en));
}

void update(int node, int l, int r, int idx) {
  if (l == r) {tree[node] = 1; return;}
  int mid = (l + r) / 2;
  if (idx <= mid) update(node * 2, l, mid, idx);
  else update(node * 2 + 1, mid + 1, r, idx);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    v.push_back({tmp, i});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    ans += query(1, 0, N - 1, v[i].second + 1, N - 1);
    update(1, 0, N - 1, v[i].second);
  }
  cout << ans << '\n';
}