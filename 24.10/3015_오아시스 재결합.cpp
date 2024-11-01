// https://www.acmicpc.net/problem/3015
#include <iostream>
#include <stack>
using namespace std;
long N, ans;
stack<pair<long, long>> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    long tmp, cnt = 1; cin >> tmp;
    while (!s.empty() && s.top().first <= tmp) {
      ans += s.top().second;
      if (s.top().first == tmp) cnt += s.top().second;
      s.pop();
    }
    if (!s.empty()) ans++;
    s.push({tmp, cnt});
  }
  cout << ans << '\n';
}