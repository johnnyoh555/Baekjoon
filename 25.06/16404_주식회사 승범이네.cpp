// https://www.acmicpc.net/problem/16404
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, st[100001], en[100001], tree[400001], lazy[400001], cnt;
vector<int> v[100001];

void dfs(int x) {
  st[x] = ++cnt;
  for (auto& nxt : v[x]) {
    dfs(nxt);
  }
  en[x] = cnt;
}

void updatelazy(int node, int l, int r) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (l != r) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update(int node, int l, int r, int s, int e, int value) {
  updatelazy(node, l, r);
  if (l > e || r < s) return;
  if (s <= l && r <= e) {
    if (l == r) {
      tree[node] += value;
    } else {
      lazy[node * 2] += value;
      lazy[node * 2 + 1] += value;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(node * 2, l, mid, s, e, value);
  update(node * 2 + 1, mid + 1, r, s, e, value);
}

void get(int node, int l, int r, int idx) {
  updatelazy(node, l, r);
  if (r < idx || idx < l) return;
  if (l == r) {
    cout << tree[node] << '\n';
    return;
  }
  int mid = (l + r) / 2;
  get(node * 2, l, mid, idx);
  get(node * 2 + 1, mid + 1, r, idx);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    int tmp; cin >> tmp;
    if (tmp <= 0) continue;
    v[tmp].push_back(i);
  }
  dfs(1);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      int c; cin >> c;
      update(1, 1, N, st[b], en[b], c);
    } else {
      get(1, 1, N, st[b]);
    }
  }
}