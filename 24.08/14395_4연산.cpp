// https://www.acmicpc.net/problem/14395
#include <iostream>
#include <queue>
#include <utility>
#include <unordered_set>
using namespace std;
long s, t;
unordered_set<long> vis;
queue<pair<long, string> > q;
string ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t;
  if (s == t) {cout << "0\n"; return 0;}
  q.push({s, ""});
  vis.insert(s);;
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    if (cur.first == t) {ans = cur.second; break;}
    if (cur.first * cur.first <= t && vis.find(cur.first * cur.first) == vis.end()) {q.push({cur.first * cur.first, cur.second + "*"}); vis.insert(cur.first * cur.first);}
    if (cur.first * 2 <= t && vis.find(cur.first * 2) == vis.end()) {q.push({cur.first * 2, cur.second + "+"}); vis.insert(cur.first * 2);}
    if (vis.find(1) == vis.end()) {q.push({1, cur.second + "/"}); vis.insert(1);}
  }
  if (!ans.size()) ans = "-1";
  cout << ans << '\n';
}