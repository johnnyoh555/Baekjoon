// https://www.acmicpc.net/problem/1038
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, ans;
vector<long> v;

void dfs(long sum, long idx) {
  v.push_back(sum);
  for (int i = 0; i < idx; i++) {
    dfs(sum * 10 + i, i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < 10; i++) dfs(i, i);
  sort(v.begin(), v.end());
  if (N >= v.size()) cout << "-1\n";
  else cout << v[N];
}