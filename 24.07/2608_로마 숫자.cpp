// https://www.acmicpc.net/problem/2608
#include <iostream>
#include <map>
using namespace std;
map<string, int> m;
string A, B;
int ans, nb[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string str[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;
  m["I"] = 1; m["V"] = 5; m["X"] = 10;
  m["L"] = 50; m["C"] = 100; m["D"] = 500;
  m["M"] = 1000; m["IV"] = 4; m["IX"] = 9;
  m["XL"] = 40; m["XC"] = 90; m["CD"] = 400;
  m["CM"] = 900;
  for (int i = 0; i < A.size(); i++) {
    if (m.find(A.substr(i, 2)) != m.end()) {
      ans += m[A.substr(i, 2)];
      i++;
    } else {
      ans += m[A.substr(i, 1)];
    }
  }
  for (int i = 0; i < B.size(); i++) {
    if (m.find(B.substr(i, 2)) != m.end()) {
      ans += m[B.substr(i, 2)];
      i++;
    } else {
      ans += m[B.substr(i, 1)];
    }
  }
  cout << ans << '\n';
  string tmp;
  int i = 0;
  while (i < 13 && ans) {
    if (ans / nb[i]) {
      tmp += str[i];
      ans -= nb[i];
    } else {
      i++;
    }
  }
  cout << tmp << '\n';
}
