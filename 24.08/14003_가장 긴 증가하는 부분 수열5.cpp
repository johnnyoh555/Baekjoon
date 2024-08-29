// https://www.acmicpc.net/problem/14003
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int N, arr[1000001], dp[1000001];
vector<int> lis, lis2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	lis.push_back(arr[1]);
  lis2.push_back(1);
	for (int i = 2; i <= N; i++) {
		if (arr[i] > lis[lis.size() - 1]) {
			lis.push_back(arr[i]);
      lis2.push_back(i);
      dp[i] = lis2[lis2.size() - 2];
		} else {
      int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[idx] = arr[i];
      lis2[idx] = i;
      if (idx != 0) {
        dp[i] = lis2[idx - 1];
      } else {
        dp[i] = 0;
      }
		}
	}
	cout << lis.size() << '\n';
  int x = lis2[lis2.size() - 1];
  stack<int> ans;
  while (x != 0) {
    ans.push(arr[x]);
    x = dp[x];
  }
  while (!ans.empty()) {
    cout << ans.top() << ' ';
    ans.pop();
  }
  cout << '\n';
}