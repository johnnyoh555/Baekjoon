// https://www.acmicpc.net/problem/14586
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long N, arr[2][300], dp[301];
vector<pair<long, long>> v;

int rft(int idx) {
  long p = v[idx].first;
  long t = v[idx].second;
  while (idx < N - 1) {
    if (v[idx + 1].first <= p + t) {
      if (v[idx + 1].first + v[idx + 1].second > p + t) {
        p = v[idx + 1].first;
        t = v[idx + 1].second;
      }
    } else {
      break;
    }
    idx++;
  }
  return idx;
}

int lft(int idx) {
  long p = v[idx].first;
  long t = v[idx].second;
  while (idx > 0) {
    if (v[idx - 1].first >= p - t) {
      if (v[idx - 1].first - v[idx - 1].second < p - t) {
        p = v[idx - 1].first;
        t = v[idx - 1].second;
      }
    } else {
      break;
    }
    idx--;
  }
  return idx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  fill (dp + 1, dp + N + 1, 2e9);
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    arr[0][i + 1] = lft(i) + 1;
    arr[1][i + 1] = rft(i) + 1;
  }
  for (int i = 1; i <= N; i++) {
    dp[i] = min(dp[i], dp[arr[0][i] - 1] + 1);
    dp[arr[1][i]] = min(dp[arr[1][i]], dp[i - 1] + 1);
  }
  cout << dp[N] << '\n';
}