// https://acmicpc.net/problem/1662
#include <iostream>
using namespace std;
string str;

int dfs(int idx) {
  int cnt = 0, flag = 0;
  for (int i = idx; i < str.size(); i++) {
    if (flag || str[i] == ')') {
      if (str[i] == '(') flag++;
      if (str[i] == ')') flag--;
      if (flag < 0) break;
    }
    else if (str[i] == '(') {
      cnt--;
      cnt += (str[i - 1] - '0') * dfs(i + 1);
      flag++;
    } else {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  cout << dfs(0) << '\n';
}