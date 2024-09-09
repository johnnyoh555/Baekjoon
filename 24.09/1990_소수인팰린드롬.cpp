// https://www.acmicpc.net/problem/1990
#include <iostream>
using namespace std;

bool check(int i) {
  string str = to_string(i);;
  for (int j = 0; j < str.size() / 2; j++)
    if (str[j] != str[str.size() - 1 - j]) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b;
  cin >> a >> b;
  if (a % 2 == 0) a++;
  for (int i = a; i <= b; i += 2) {
    if (!check(i)) {
      bool flag = 0;
      for (int j = 3; j * j <= i; j += 2)
         if (i % j == 0) {flag = 1; break;}
      if (!flag) cout << i << "\n";
    }
  }
  cout << "-1\n";
}