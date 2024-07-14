// https://www.acmicpc.net/problem/2631
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, arr[201];
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  v.push_back(arr[0]);
  for (int i = 1; i < N; i++) {
    if (arr[i] > v[v.size() - 1]) {
      v.push_back(arr[i]);
    } else {
      v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
    }
  }
  cout << N - v.size() << '\n';
}