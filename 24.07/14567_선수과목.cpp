// https://www.acmicpc.net/problem/14567
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, M, arr[1001];
vector<int> v[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
  }
  for (int i = 1; i <= N; i++)
    for (auto nxt : v[i]) 
      arr[nxt] = max(arr[i] + 1, arr[nxt]);
  for (int i = 1; i <= N; i++)
    cout << arr[i] + 1 << ' ';
  cout << '\n';
}