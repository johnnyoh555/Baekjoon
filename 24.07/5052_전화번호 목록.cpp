// https://www.acmicpc.net/problem/5052
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int n; cin >> n;
    unordered_set<string> us;
    for (int i = 0; i < n; i++) {
      string tmp; cin >> tmp;
      us.insert(tmp);
    }
    bool flag = 0;
    for (auto it = us.begin(); it != us.end(); it++) {
      for (int i = 1; i < it->size(); i++) {
        if (us.find(it->substr(0, i)) != us.end()) {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) cout << "YES\n";
    else cout << "NO\n";
  }
}