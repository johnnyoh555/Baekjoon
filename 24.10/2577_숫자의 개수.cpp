// https://www.acmicpc.net/problem/2577
#include <iostream>
using namespace std;
int d[10], A, B, C;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> C;
  string str = to_string(A * B * C);
  for (int i = 0; i < str.size(); i++) d[str[i] - '0']++;
  for (int i = 0; i < 10; i++) cout << d[i] << '\n';
}