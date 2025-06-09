// https://www.acmicpc.net/problem/13925
#include <iostream>
using namespace std;
long long N, M, arr[100001], tree[400001], a, st, en, v, MOD = 1e9 + 7, lazy[400001][3];

void lazyupdate(int node, long long l, long long r) {
  if (lazy[node][0] == 1 && lazy[node][1] == 0 && lazy[node][2] == 0) return;
  if (lazy[node][2]) {
    tree[node] = lazy[node][2] * (r - l + 1) % MOD;
    if (l != r) {
      lazy[node * 2][0] = 1;
      lazy[node * 2][1] = 0;
      lazy[node * 2][2] = lazy[node][2];
      lazy[node * 2 + 1][0] = 1;
      lazy[node * 2 + 1][1] = 0;
      lazy[node * 2 + 1][2] = lazy[node][2];
    }
    lazy[node][2] = 0;
  }
  tree[node] = (tree[node] * lazy[node][0]) % MOD;
  tree[node] = (tree[node] + (lazy[node][1] * (r - l + 1) % MOD)) % MOD;
  if (l != r) {
    lazy[node * 2][0] = (lazy[node * 2][0] * lazy[node][0]) % MOD;
    lazy[node * 2][1] = ((lazy[node * 2][1] * lazy[node][0]) % MOD + lazy[node][1]) % MOD;
    lazy[node * 2 + 1][0] = (lazy[node * 2 + 1][0] * lazy[node][0]) % MOD;
    lazy[node * 2 + 1][1] = ((lazy[node * 2 + 1][1] * lazy[node][0]) % MOD + lazy[node][1]) % MOD;
  }
  lazy[node][0] = 1;
  lazy[node][1] = 0;
}

void update(int node, long long l, long long r) {
  lazyupdate(node, l, r);
  if (r < st || en < l) return;
  if (st <= l && r <= en) {
    if (a == 1) {
      lazy[node][1] = (lazy[node][1] + v) % MOD;
    } else if (a == 2) {
      lazy[node][0] = (lazy[node][0] * v) % MOD;
      lazy[node][1] = (lazy[node][1] * v) % MOD;
    } else {
      lazy[node][0] = 1;
      lazy[node][1] = 0;
      lazy[node][2] = v;
    }
    lazyupdate(node, l, r);
    return;
  }
  long long mid = (l + r) / 2;
  update(node * 2, l, mid);
  update(node * 2 + 1, mid + 1, r);
  tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

void init (int node, long long l, long long r) {
  if (l == r) {tree[node] = arr[l]; return;}
  long long mid = (l + r) / 2;
  init(node * 2, l, mid);
  init(node * 2 + 1, mid + 1, r);
  tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

long long get(int node, long long l, long long r) {
  lazyupdate(node, l, r);
  if (r < st || en < l) return 0;
  if (st <= l && r <= en) return tree[node];
  long long mid = (l + r) / 2;
  return (get(node * 2, l, mid) + get(node * 2 + 1, mid + 1, r)) % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 0; i <= 400000; i++) lazy[i][0] = 1;
  init(1, 1, N);
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> st >> en;
    if (a < 4) {
      cin >> v;
      update(1, 1, N);
    } else {
      cout << get(1, 1, N) << '\n';
    }
  }
}