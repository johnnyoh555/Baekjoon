// https://www.acmicpc.net/problem/22968
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long T, V, a = 1, b = 1;
vector<long long> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  v.push_back(1);
  v.push_back(2);
  for (int i = 2; ; i++) {
    v.push_back(v[i - 1] + a + b);
    swap(a, b);
    a += b;
    if (v[i] > 1000000000) break;
  }
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> V;
    cout << upper_bound(v.begin(), v.end(), V) - v.begin() << '\n';
  }
}