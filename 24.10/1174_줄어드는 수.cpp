// https://www.acmicpc.net/problem/1174
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long> v;
int N;

void dfs(long sum, long x) {
  for (long i = 0; i < x; i++) {
    v.push_back({sum * 10 + i});
    dfs(sum * 10 + i, i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  dfs(0, 10);
  sort(v.begin(), v.end());
  cin >> N;
  if (N > v.size()) cout << "-1\n";
  else cout << v[N - 1] << '\n';
}