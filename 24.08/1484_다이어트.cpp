// https://www.acmicpc.net/problem/1484
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int G; cin >> G;
  long st = 1, en = 2;
  while (en <= 100000) {
    long x = st * st, y = en * en;
    if (st == en || x + G > y) en++;
    else if (x + G < y) st++;
    else if (x + G == y) {v.push_back(en); en++;}
  }
  if (!v.size()) cout << "-1\n";
  else for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
}