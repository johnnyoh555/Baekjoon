// https://www.acmicpc.net/problem/1188
#include <iostream>
using namespace std;
int N, M;

int ft(int a, int b) {
  if (a % b == 0) return b;
  return ft(b, a % b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  cout << M - ft(N, M) << '\n';
}