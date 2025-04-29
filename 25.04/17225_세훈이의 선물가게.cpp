// https://www.acmicpc.net/problem/17225
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A, B, N, Blue_Time, Red_Time, Blue_idx, Red_idx, cnt = 1;
vector<pair<int, int>> Blue_Order, Red_Order;
vector<int> Blue_ans, Red_ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> N;
  for (int i = 0; i < N; i++) {
    int x, y; char c; cin >> x >> c >> y;
    if (c == 'B') {
      Blue_Order.push_back({x, y});
    } else {
      Red_Order.push_back({x, y});
    }
  }
  sort(Blue_Order.begin(), Blue_Order.end());
  sort(Red_Order.begin(), Red_Order.end());
  while (true) {
    if (Blue_idx == Blue_Order.size()) Blue_Time = 2e9;
    else Blue_Time = max(Blue_Time, Blue_Order[Blue_idx].first);
    if (Red_idx == Red_Order.size()) Red_Time = 2e9;
    else Red_Time = max(Red_Time, Red_Order[Red_idx].first);
    if (Blue_Time == 2e9 && Red_Time == 2e9) break;
    if (Blue_Time <= Red_Time) {
      Blue_ans.push_back(cnt);
      Blue_Time += A;
      if (Blue_Order[Blue_idx].second == 1) Blue_idx++;
      else Blue_Order[Blue_idx].second--; 
    } else {
      Red_ans.push_back(cnt);
      Red_Time += B;
      if (Red_Order[Red_idx].second == 1) Red_idx++;
      else Red_Order[Red_idx].second--; 
    }
    cnt++;
  }
  cout << Blue_ans.size() << '\n';
  for (int i = 0; i < Blue_ans.size() ; i++) {
    cout << Blue_ans[i] << (i == Blue_ans.size() - 1 ? '\n' : ' ');
  }
  cout << Red_ans.size() << '\n';
  for (int i = 0; i < Red_ans.size() ; i++) {
    cout << Red_ans[i] << (i == Red_ans.size() - 1 ? '\n' : ' ');
  }
}