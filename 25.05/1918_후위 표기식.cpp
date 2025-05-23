// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <stack>
using namespace std;
string str, ans;
stack<char> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '*' || str[i] == '/') {
      while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
        ans.push_back(s.top());
        s.pop();
      }
      s.push(str[i]);
    } else if (str[i] == '-' || str[i] == '+') {
      while (!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')) {
        ans.push_back(s.top());
        s.pop();
      }
      s.push(str[i]);
    } else if (str[i] == '(') {
      s.push(str[i]);
    } else if (str[i] == ')') {
      while (s.top() != '(') {
        ans.push_back(s.top());
        s.pop();
      }
      s.pop();
    } else {
      ans.push_back(str[i]);
    }
  }
  while (!s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }
  cout << ans << '\n';
}