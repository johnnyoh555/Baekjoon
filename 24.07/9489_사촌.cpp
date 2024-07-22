// https://www.acmicpc.net/problem/9489
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0) break;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int tmp; cin >> tmp;
      v.push_back(tmp);
    }
    vector<int> line[1001];
    int idx = 0, p[1001], a;
    p[0] = 0;
    for (int i = 1; i < v.size(); i++) {
      line[idx].push_back(i);
      p[i] = idx;
      if (v[i] == k) a = i;
      if (!(i < v.size() - 1 && v[i] + 1 == v[i + 1])) idx++;
    }
    int tmp = p[p[a]];
    int ans = 0;
    for (int i = 0; i < line[tmp].size(); i++) {
      if (line[tmp][i] == p[a]) continue;
      ans += line[line[tmp][i]].size();
    }
    if (k == v[0] || p[a] == 0) cout << "0\n";
    else cout << ans << '\n';
  }
}
