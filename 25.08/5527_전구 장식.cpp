// https://www.acmicpc.net/problem/5527
#include <iostream>
#include <vector>
using namespace std;
int N, pre = -1, cnt, a, mx;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  v.push_back(0);
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (a != pre) {
      cnt++;
    } else {
      v.push_back(cnt);
      cnt = 1;
    }
    pre = a;
  }
  v.push_back(cnt);
  v.push_back(0);
  for (int i = 1; i <= v.size() - 2; i++) {
    if (mx < v[i - 1] + v[i] + v[i + 1])
      mx = v[i - 1] + v[i] + v[i + 1];
  }
  cout << mx << '\n';
}