// https://www.acmicpc.net/problem/18116
#include <iostream>
using namespace std;
int N, arr[1000001];

int find(int x) {
  if (arr[x] < 0) return x;
  return arr[x] = find(arr[x]);
}

void uf(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  arr[a] += arr[b];
  arr[b] = a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= 1e6; i++) arr[i] = -1;
  for (int i = 0; i < N; i++) {
    char c; cin >> c;
    if (c == 'I') {
      int a, b; cin >> a >> b;
      uf(a, b);
    } else {
      int a; cin >> a;
      cout << -arr[find(a)] << '\n';
    }
  }
}