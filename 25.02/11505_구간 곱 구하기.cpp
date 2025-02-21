// https://www.acmicpc.net/problem/11505
#include <iostream>
using namespace std;
typedef unsigned long ul;
ul N, M, K, mod = 1000000007, arr[1000001], sum[1000001], segTree[4000001];

ul init(ul node, ul st, ul en) {
  if (st == en) return segTree[node] = arr[st];
  ul mid = (st + en) / 2;
  return segTree[node] = (init(node * 2, st, mid) * init(node * 2 + 1, mid + 1, en)) % mod;
}

ul update(ul node, ul st, ul en, ul idx) {
  if (!(st <= idx && idx <= en)) return segTree[node];
  if (st == en) return segTree[node] = arr[st];

  ul mid = (st + en) / 2;
  return segTree[node] = update(node * 2, st, mid, idx) * update(node * 2 + 1, mid + 1, en, idx) % mod;
}

ul cal(ul node, ul st, ul en, ul l, ul r) {
  if (l <= st && en <= r) return segTree[node];
  if (en < l || r < st) return 1;
  ul mid = (st + en) / 2;
  return (cal(node * 2, st, mid, l, r) * cal(node * 2 + 1, mid + 1, en, l, r)) % mod;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  arr[0] = 1;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    sum[i] = (sum[i - 1] * arr[i]) % mod;
  }
  init(1, 1, N);
  for (int i = 0; i < M + K; i++) {
    ul a, b, c; cin >> a >> b >> c;
    if (a == 1) {arr[b] = c; update(1, 1, N, b);}
    else cout << cal(1, 1, N, b, c) << '\n';
  }
}