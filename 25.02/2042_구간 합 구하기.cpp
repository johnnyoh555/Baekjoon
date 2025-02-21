// https://www.acmicpc.net/problem/2042
#include <iostream>
using namespace std;
long N, M, K, arr[1000001], sum[1000001], segTree[4000001];

long init(long node, long st, long end) {
  if (st == end) return segTree[node] = arr[st];
  long mid = (st + end) / 2;

  return segTree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(long node, long st, long end, long t, long diff) {
  if (st <= t && t <= end) segTree[node] += diff;
  else return;
  if (st == end) return;
  long mid = (st + end) / 2;
  update(node * 2, st, mid, t, diff);
  update(node * 2 + 1, mid + 1, end, t, diff);
}

long add(long l, long r, long node, long st, long end) {
  if (l <= st && end <= r) return segTree[node];

  if (r < st || end < l) return 0;
  long m = (st + end) / 2;
  return add(l, r, node * 2, st, m) + add(l, r, node * 2 + 1, m + 1, end);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    sum[i] = sum[i - 1] + arr[i];
  }
  init(1, 1, N);
  for (int i = 0; i < M + K; i++) {
    long a, b, c; cin >> a >> b >> c;
    if (a == 1) {update(1, 1, N, b, c - arr[b]); arr[b] = c;}
    else cout << add(b, c, 1, 1, N) << '\n';
  }
}