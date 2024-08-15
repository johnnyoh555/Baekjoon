// https://www.acmicpc.net/problem/2436
#include <iostream>
#include <vector>
using namespace std;
long sum, a, b, mn = 2e9 + 1, c, d;
vector<long> v;

bool check(long x, long y) {
long i = 1, j = 1, xx = x, yy = y;

  while (xx != yy && xx <= b && yy <= b) {
    if (xx < yy) {
      i++;
      xx = x * i;
    } else {
      j++;
      yy = y * j;
    }
  }
  if (xx == b && yy == b) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  sum = a * b;
  for (long i = 1; i * a <= b; i++) {
    if (b % (i * a) == 0) v.push_back(i * a);
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] * v[j] != sum) continue;
      if (check(v[i], v[j]) && v[i] + v[j] < mn) {
        mn = v[i] + v[j];
        c = v[i];
        d = v[j];
      }
    }
  }
  if (a == b) {c = a; d = b;}
  cout << c << ' ' << d << '\n';
}