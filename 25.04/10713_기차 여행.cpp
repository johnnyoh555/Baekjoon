// https://www.acmicpc.net/problem/10713
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
long N, M, idx, arr[3][100001], x, y, ans;
vector<pair<int, int>> st;
priority_queue<int, vector<int>, greater<int>> en;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  cin >> x;
  for (int i = 0; i < M - 1; i++) {
    cin >> y;
    x < y ? st.push_back({x, y}) : st.push_back({y , x});
    x = y;
  }
  sort(st.begin(), st.end());
  for (int i = 1; i < N; i++) {
    cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
  }
  for (int i = 1; i <= 100000; i++) {
    while (!st.empty() && st[idx].first == i) {
      en.push(st[idx].second);
      idx++;
    }
    while (!en.empty() && en.top() == i) {
      en.pop();
    }
    ans += min(arr[0][i] * en.size(), arr[1][i] * en.size() + arr[2][i]);
  }
  cout << ans << '\n';
}