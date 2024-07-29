// https://www.acmicpc.net/problem/17609
#include <iostream>
using namespace std;

int check(string str, int st, int en, int dep) {
  while (st < en) {
    if (str[st] != str[en]) {
      if (dep) {
        return 2;
      } else {
        int a = check(str, st + 1, en, dep + 1);
        int b = check(str, st, en - 1, dep + 1);
        if (a < b) return a;
        else return b;
      }
    }
    st++; en--;
  }
  return dep;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    string str; cin >> str; 
    int st = 0, en = str.size() - 1;
    cout << check(str, st, en, 0) << '\n';
  }
}