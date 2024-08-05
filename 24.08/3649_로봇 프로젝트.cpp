// https://www.acmicpc.net/problem/3649
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int x, n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> x) {
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int tmp; cin >> tmp;
      v.push_back(tmp);
    }
    x *= 10000000;
    sort(v.begin(), v.end());
    bool flag = 0;
    for (int i = 0; i < v.size(); i++) {
      if (binary_search(v.begin() + i + 1, v.end(), x - v[i])) {
        cout << "yes" << ' ' << v[i] << ' ' << x - v[i] << '\n';
        flag = 1;
        break;
      }
    }
    if (!flag) cout << "danger\n";
  }
}