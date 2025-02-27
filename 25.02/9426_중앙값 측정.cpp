// https://www.acmicpc.net/problem/9426
#include <iostream>
using namespace std;
int arr[250001], N, K, SIZE = 65535, tree[262144];
long ans;

void update(int node, int st, int en, int t, int v) {
  if (t < st || en < t) return;
  if (st == en) {
    tree[node] += v;
    return;
  }
  int mid = (st + en) / 2;
  update(node * 2, st, mid, t, v);
  update(node * 2 + 1, mid + 1, en, t, v);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int find(int node, int st, int en, int t) {
  if (st == en) return st;

  int mid = (st + en) / 2;
  if (tree[node * 2] >= t) return find(node * 2, st, mid, t);
  else return find(node * 2 + 1, mid + 1, en, t - tree[node * 2]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  int mid = (K + 1) / 2;
  for (int i = 1; i <= N; i++) {
    update(1, 0, SIZE, arr[i], 1);
    if (i < K) continue;
    ans += (long)find(1, 0, SIZE, mid);
    update(1, 0, SIZE, arr[i - K + 1], -1);
  }
  cout << ans << '\n';
}