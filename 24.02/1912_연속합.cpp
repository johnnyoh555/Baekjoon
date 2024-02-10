// https://www.acmicpc.net/problem/1912

#include <iostream>

using namespace std;

int d[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> d[i];
  }
  for (int i = 2; i <= N; i++) {
    d[i] = max(d[i], d[i - 1] + d[i]);
  }
  int max = d[1];
  for (int i = 2; i <= N; i++) {
    if (d[i] > max) max = d[i];
  }
  cout << max << '\n';
}