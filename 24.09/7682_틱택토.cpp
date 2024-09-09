// https://www.acmicpc.net/problem/7682
#include <iostream>
using namespace std;
string str;

int check(char c) {
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    if (str[i] == c && str[i + 3] == c && str[i + 6] == c) cnt++;
    if (str[i * 3] == c && str[i * 3 + 1] == c && str[i * 3 + 2] == c) cnt++;
  }
  if (str[0] == c && str[4] == c && str[8] == c) cnt++;
  if (str[2] == c && str[4] == c && str[6] == c) cnt++;
  return cnt;
}

int count(char c) {
  int cnt = 0;
  for (int i = 0; i < str.size(); i++)
    if (str[i] == c) cnt++;
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> str) {
    bool flag = 0;
    if (str == "end") break;
    int x = count('X');
    int o = count('O');
    if (o > x || x - 1 > o) flag = 1;
    int xx = check('X');
    int oo = check('O');
    if (xx && oo || x != 5 && !xx && !oo) flag = 1;
    else if (oo && x != o) flag = 1;
    else if (xx && o == x) flag = 1;
    if (flag) cout << "invalid\n";
    else cout << "valid\n";
  }
}