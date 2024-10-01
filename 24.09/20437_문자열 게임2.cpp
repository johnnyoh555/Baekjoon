// https://www.acmicpc.net/problem/20437
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    string str; cin >> str;
    int g; cin >> g;
    int mx = 0, mn = 2e9 + 1;
    for (int i = 0; i < 26; i++) {
      vector<int> idx;
      for (int j = 0; j < str.size(); j++)
        if (str[j] == 'a' + i)
          idx.push_back(j);
      for (int j = 0; j + g - 1 < idx.size(); j++) {
        int tmp = idx[j + g - 1] - idx[j] + 1;
        if (tmp > mx) mx = tmp;
        if (tmp < mn) mn = tmp;
      }
    }
    if (mn == 2e9 + 1) cout << "-1\n";
    else cout << mn << ' ' << mx << '\n';
  }
}