// https://www.acmicpc.net/problem/6443
#include <iostream>
#include <cstring>
using namespace std;
int T, arr[26], word[20];
string str;

void dfs(string& s) {
  if (s.size() == str.size()) {
    cout << s << '\n';
    return;
  }
  for (int i = 0; i < 26; i++) {
    if (arr[i]) {
      arr[i]--;
      string tmp = s;
      tmp.push_back('a' + i);
      dfs(tmp);
      arr[i]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> str;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < str.size(); i++)
      arr[str[i] - 'a']++;
    string s;
    dfs(s);
  }
}