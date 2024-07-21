// https://www.acmicpc.net/problem/19942
#include <iostream>
#include <vector>
using namespace std;
int N, a, b, c, d, arr[16][5], ans = 2e9 + 1;
vector<int> vv;

bool cmp(vector<int>& v) {
  for(int i = 0; i < v.size() && i < vv.size(); i++) {
    if (v[i] < vv[i]) return true;
    else if (v[i] > vv[i]) return false;
  }
  return v.size() < vv.size();
}

void dfs(int dep, int cnt, vector<int> v) {
  if (dep == N) {
    if (a <= 0 && b <= 0 && c <= 0 && d <= 0 && ans >= cnt) {
      if (ans > cnt || vv.empty() || cmp(v)) vv = v;
      ans = cnt;
    }
    return;
  }
  a -= arr[dep][0];
  b -= arr[dep][1];
  c -= arr[dep][2];
  d -= arr[dep][3];
  v.push_back(dep + 1);
  dfs(dep + 1, cnt + arr[dep][4], v);
  v.pop_back();
  a += arr[dep][0];
  b += arr[dep][1];
  c += arr[dep][2];
  d += arr[dep][3];
  dfs(dep + 1, cnt, v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> a >> b >> c >> d;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }
  vector<int> v;
  dfs(0, 0, v);
  if (ans == 2e9 + 1) ans = -1;
  cout << ans << '\n';
  for (int i = 0; i < vv.size(); i++) {
    cout << vv[i] << ' ';
  }
  cout << '\n';
}