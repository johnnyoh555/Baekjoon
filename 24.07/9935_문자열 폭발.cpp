// https://www.acmicpc.net/problem/9935
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
string str, bomb;
stack<char> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str >> bomb;
  for (int i = 0; i < str.size(); i++) {
    s.push(str[i]);
    if (s.size() >= bomb.size() && str[i] == bomb[bomb.size() - 1]) {
      string tmp;
      for (int j = bomb.size(); j > 0; j--) {
        tmp.push_back(s.top()); s.pop();
      }
      reverse(tmp.begin(), tmp.end());
      if (tmp != bomb) {
        for (int i = 0; i < tmp.size(); i++) s.push(tmp[i]);
      }
    }
  }
  if (s.empty()) cout << "FRULA\n";
  else {
    string ans;
    while (!s.empty()) {
      ans.push_back(s.top());
      s.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
}