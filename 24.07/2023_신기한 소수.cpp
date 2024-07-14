#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int N;

bool check(int x) {
  if (x == 0 || x == 1) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

void dfs(int sum, int dep) {
  if (dep == N) {
    v.push_back(sum);
    return;
  }
  sum *= 10;
  for (int i = 1; i < 10; i++) {
    if (dep && i % 2 == 0) continue;
    if (check(sum + i)) dfs((sum + i), dep + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  dfs(0, 0);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }
}