// https://www.acmicpc.net/problem/1826
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, des, fuel, cnt;
priority_queue<int> pq;
vector<pair<int, int>>  v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  cin >> des >> fuel;
  for (int i = 0; i < N; i++) {
    while (!pq.empty() && fuel < v[i].first && fuel < des) {
      fuel += pq.top();
      pq.pop();
      cnt++;
    }
    if (v[i].first <= fuel) {
      pq.push({v[i].second});
    } else {
      cout << "-1\n"; return 0;
    }
  }
  while (fuel < des && !pq.empty()) {
    fuel += pq.top(); pq.pop();
    cnt++;
  }
  if (fuel < des) cout << "-1\n";
  else cout << cnt << '\n';
}