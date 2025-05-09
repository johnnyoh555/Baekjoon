// https://www.acmicpc.net/problem/20956
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001], N, M, tree[400004], flag;

void init(int node, int l, int r) {
  if (l == r) {
    tree[node] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  init(node * 2, l, mid);
  init(node * 2 + 1, mid + 1, r);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int get(int node, int l, int r) {
  if (l == r) {
    if (tree[node] % 7 == 0) flag = !flag;
    tree[node] = 0;
    return l;
  }
  int mid = (l + r) / 2, tmp;
  if (tree[node * 2] == tree[node * 2 + 1] && !flag || tree[node * 2] > tree[node * 2 + 1]) {
    tmp = get(node * 2, l, mid);
  } else {
    tmp = get(node * 2 + 1, mid + 1, r);
  }
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
  return tmp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  for (int i = 0; i < M; i++) cout << get(1, 1, N) << '\n';
}