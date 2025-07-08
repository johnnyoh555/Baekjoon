// https://www.acmicpc.net/problem/18227
#include <iostream>
#include <vector>
using namespace std;
long N, C, Q, dep[200001], st[200001], en[200001], tree[800001], cnt;
vector<int> v[200001];

void dfs(int x) {
  st[x] = ++cnt;
  for (auto nxt : v[x]) if (!dep[nxt]) {
    dep[nxt] = dep[x] + 1;
    dfs(nxt);
  }
  en[x] = cnt;
}

void update(int node, int l, int r, int idx) {
  if (r < idx || idx < l) return;
  tree[node]++;
  if (l == r) return;
  int mid = (l + r) / 2;
  update(node * 2, l, mid, idx);
  update(node * 2 + 1, mid + 1, r, idx);
}

int get(int node, int l, int r, int s, int e) {
  if (r < s || e < l) return 0;
  if (s <= l && r <= e) return tree[node];
  int mid = (l + r) / 2;
  return get(node * 2, l, mid, s, e) + get(node * 2 + 1, mid + 1, r, s, e);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> C;
  for (int i = 1; i < N; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dep[C] = 1;
  dfs(C);
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    if (a == 1) {
      update(1, 1, N, st[b]);
    } else {
      cout << get(1, 1, N, st[b], en[b]) * dep[b] << '\n';
    }
  }
}