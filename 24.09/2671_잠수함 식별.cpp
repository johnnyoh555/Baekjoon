// https://www.acmicpc.net/problem/2671
#include <iostream>
#include <regex>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str; cin >> str;
  regex re("(100+1+|01)+");
  if (regex_match(str, re)) cout << "SUBMARINE\n";
  else cout << "NOISE\n";
}