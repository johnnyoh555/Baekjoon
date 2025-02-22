// https://www.acmicpc.net/problem/5639
#include <iostream>
using namespace std;
int N, idx, root, arr[2][1000001], p[1000001];

void ft(int node, int target) {
  if (!arr[1][node]) {arr[1][node] = target; p[target] = node;}
  else ft(arr[1][node], target);
}

void dfs(int node) {
  if (arr[0][node]) dfs(arr[0][node]);
  if (arr[1][node]) dfs(arr[1][node]);
  cout << node << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> N) {
    if (!root) {
      root = N;
    } else if (N < idx) {
      arr[0][idx] = N;
      p[N] = idx;
    } else {
      while (N > p[idx] && p[idx]) {
        idx = p[idx];
      }
      ft(idx, N);
    }
    idx = N;
  }
  dfs(root);
}

/*
50
30
24
5
27
25
26
28
29
45
98
52
60
106
109
108
110*/