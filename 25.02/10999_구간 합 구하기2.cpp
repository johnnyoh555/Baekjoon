// https://www.acmicpc.net/problem/10999
#include <iostream>
using namespace std;
long arr[1000001], tree[4000001], lazy[4000001], N, M, K;

long init(int node, int st, int en) {
  if (st == en) return tree[node] = arr[st];
  int mid = (st + en) / 2;
  return tree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, en);
}


void updateLazy(int node, long st, long en) {
  if (!lazy[node]) return;
  
  tree[node] += lazy[node] * (en - st + 1);
  if (st != en) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
  return;
}

void update(int node, long st, long en, int l, int r, long diff) {
  updateLazy(node, st, en);
  if (r < st || en < l) return;
  
  if (l <= st && en <= r) {
    tree[node] += diff * (en - st + 1);
    if (st != en) {
      lazy[node * 2] += diff;
      lazy[node * 2 + 1] += diff;
    }
    return;
  }
  
  int mid = (st + en) / 2;
  update(node * 2, st, mid, l, r, diff);
  update(node * 2 + 1, mid + 1, en, l, r, diff);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
  return;
}

long sum(int node, long st, long en, int l, int r) {
  updateLazy(node, st, en);
  if (r < st || en < l) return 0;
  if (l <= st && en <= r) return tree[node];
  int mid = (st + en) / 2;
  return sum(node * 2, st, mid, l, r) + sum(node * 2 + 1, mid + 1, en, l, r);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  for (int i = 0; i < M + K; i++) {
    long a;
    cin >> a;
    if (a == 1) {
      long b, c, d;
      cin >> b >> c >> d;
      update(1, 1, N, b, c, d);
    } else {
      long b, c;
      cin >> b >> c;
      cout << sum(1, 1, N, b, c) << '\n';
    }
  }
}