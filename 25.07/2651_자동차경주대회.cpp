// https://www.acmicpc.net/problem/2651
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
long long D, N, arr[102], t[102], d[102], b[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> D >> N;
  fill(d, d + 102, 2e11);
  d[0] = 0;
  for (int i = 1; i <= N + 1; i++) cin >> arr[i];
  for (int i = 1; i <= N; i++) cin >> t[i];
  for (int i = 1; i <= N + 1; i++) {
    long long sum = 0;
    for (int j = 0; j < i; j++) {
      sum += arr[i - j];
      if (sum > D) break;
      if (d[i] > d[i - j - 1] + t[i]) {
        d[i] = d[i - j - 1] + t[i];
        b[i] = i - j - 1;
      }
    }
  }
  cout << d[N + 1] << '\n';
  int x = N + 1;
  stack<int> s;
  while (b[x]) {
    s.push(b[x]);
    x = b[x];
  }
  cout << s.size() << '\n';
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
  cout << '\n';
}