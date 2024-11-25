// https://www.acmicpc.net/problem/1863
#include <iostream>
#include <stack>
using namespace std;
int N, ans;
stack<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  while (N--) {
    int a, b; cin >> a >> b;
    if (s.empty() || s.top() < b) {
      s.push(b);
    } else {
      while (!s.empty() && s.top() > b) {
        ans++;
        s.pop();
      }
      if (s.empty() || s.top() != b) {
        s.push(b);
      }
    }
  }
  while (!s.empty() && s.top()) {
    s.pop();
    ans++;
  }
  cout << ans << '\n';
}