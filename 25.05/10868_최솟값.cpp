// https://www.acmicpc.net/problem/10868
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001], tree[400004], N, M, a, b;

void init(int node, int l, int r) {
  if (l == r) {
    tree[node] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  init(node * 2, l, mid);
  init(node * 2 + 1, mid + 1, r);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int get(int node, int l, int r, int st, int en) {
  if (r < st || en < l) return 2e9;
  if (st <= l && r <= en) return tree[node];
  int mid = (l + r) / 2;
  return min(get(node * 2, l, mid, st, en), get(node * 2 + 1, mid + 1, r, st, en));
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << get(1, 1, N, a, b) << '\n';
  }
}