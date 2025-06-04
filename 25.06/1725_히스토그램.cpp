// https://www.acmicpc.net/problem/1725
#include <iostream>
#include <stack>
using namespace std;
long arr[100002], N, ans;
stack<long> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  arr[0] = -1;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 0; i <= N + 1; i++) {
    while (!s.empty() && arr[s.top()] >= arr[i]) {
      long tmp = arr[s.top()]; s.pop();
      long len = i - s.top() - 1;
      if (ans < len * tmp) ans = len * tmp;
    }
    s.push(i);
  }
  cout << ans << '\n';
}