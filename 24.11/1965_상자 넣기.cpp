// https://www.acmicpc.net/problem/1965
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    int it = lower_bound(v.begin(), v.end(), x) - v.begin();
    if (it == v.size()) {
      v.push_back(x);
    } else {
      v[it] = x;
    }
  }
  cout << v.size() << '\n';
}