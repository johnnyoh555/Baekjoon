// https://www.acmicpc.net/problem/28707
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
#include <unordered_map>
using namespace std;
int N, M;
vector<tuple<int, int, int>> sw;
string str;
unordered_map<string, int> um;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N; 
  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    str.push_back('0' + tmp - 1);
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    sw.push_back({c, a, b});
  }
  pq.push({0, str});
  um[str] = 0;
  sort(str.begin(), str.end());
  while (!pq.empty()) {
    int c; string x; tie(c, x) = pq.top(); pq.pop();
    if (um.find(x) != um.end() && um[x] != c) continue;
    for (int i = 0; i < sw.size(); i++) {
      int v, a, b; tie(v, a, b) = sw[i];
      string tmp = x;
      swap(tmp[a - 1], tmp[b - 1]);
      if (um.find(tmp) != um.end() && um[tmp] <= c + v) continue;
      um[tmp] = c + v;
      pq.push({c + v, tmp});
    }
  }
  if (um.find(str) != um.end()) cout << um[str] << '\n';
  else cout << "-1\n";
}