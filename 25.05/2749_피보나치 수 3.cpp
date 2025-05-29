// https://www.acmicpc.net/problem/2749
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
long n, mod = 1000000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  v.push_back(0);
  v.push_back(1);
  int idx = 2;
  while (idx) {
    int tmp = (v[idx - 2] + v[idx - 1]) % mod;
    if (tmp == 1 && !v[idx - 1]) {
      v.pop_back();
      break;
    }
    v.push_back(tmp);
    idx++;
  }
  cout << v[(n % v.size())] << '\n';
}