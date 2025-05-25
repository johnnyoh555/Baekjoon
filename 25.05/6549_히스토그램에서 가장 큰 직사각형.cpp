// https://www.acmicpc.net/problem/6549
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
long arr[100002], n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  while (cin >> n) {
    if (n == 0) break;
    stack<long> s;
    long ans = 0;
    arr[n + 1] = 0;
    for (long i = 1; i <= n; i++) cin >> arr[i];
    for (long i = 1; i <= n + 1; i++) {
      while (!s.empty() && arr[s.top()] >= arr[i]) {
        long tmp = s.top(); s.pop();
        long len = i - (s.empty() ? 0 : s.top()) - 1;
        ans = max(ans, arr[tmp] * len);
      }
      s.push(i);
    }
    cout << ans << '\n';
  }
}