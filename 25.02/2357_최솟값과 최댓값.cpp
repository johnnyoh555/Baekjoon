// https://www.acmicpc.net/problem/2357
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[100001], minTree[400001], maxTree[400001], mn, mx;

void init(int node, int st, int en) {
  if (st == en) {
    minTree[node] = arr[st];
    maxTree[node] = arr[st];
    return;
  }
  int mid = (st + en) / 2;
  init(node * 2, st, mid);
  init(node * 2 + 1, mid + 1, en);
  minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
  maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

void cal(int node, int st, int en, int l, int r) {
  if (en < l || r < st) return;
  if (l <= st && en <= r) {
    mn = min(mn, minTree[node]);
    mx = max(mx, maxTree[node]);
    return;
  }
  int mid = (st + en) / 2;
  cal(node * 2, st, mid, l, r);
  cal(node * 2 + 1, mid + 1, en, l, r);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    mn = 1e9 + 1; mx = -1;
    cal(1, 1, N, a, b);
    cout << mn << ' ' << mx << '\n';
  }
}