// https://www.acmicpc.net/problem/30960
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, sum, ans = 2e9 + 1;
vector<int> v, odd, even;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < v.size(); i += 2) odd.push_back(v[i] - v[i - 1]);
  for (int i = 2; i < v.size(); i += 2) {even.push_back(v[i] - v[i - 1]); sum += v[i] - v[i - 1];}
  for (int i = 0; i < odd.size(); i++) {
    sum += odd[i];
    if (i >= 1) sum -= even[i - 1];
    if (ans > sum) ans = sum;
  }
  cout << ans << '\n';
}