// https://www.acmicpc.net/problem/16472
#include <iostream>
using namespace std;
int N, st, en, d[26], cnt, ans;
string str;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> str;
  while (en < str.size()) {
    if (!d[str[en] - 'a']) cnt++;
    d[str[en] - 'a']++;
    while (cnt > N) {
      d[str[st] - 'a']--;
      if (!d[str[st] - 'a']) cnt--;
      st++;
    }
    if (en - st + 1 > ans) ans = en - st + 1;
    en++;
  }
  cout << ans << '\n';
}