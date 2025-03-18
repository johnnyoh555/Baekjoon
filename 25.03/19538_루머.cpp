// https://www.acmicpc.net/problem/19538
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, arr[200001];
vector<int> v[200001];
queue<int> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    arr[i] = -1;
    int tmp;
    while (cin >> tmp) {
      if (!tmp) break;
      v[i].push_back(tmp);
    }
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    int tmp; cin >> tmp;
    q.push(tmp);
    arr[tmp] = 0;
  }
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : v[cur]) {
      if (arr[nxt] != -1) continue;
      int cnt = 0;
      for (int nxt2 : v[nxt])
        if (arr[nxt2] != -1 && arr[nxt2] <= arr[cur]) cnt++;
      if (cnt < (v[nxt].size() + 1) / 2) continue;
      arr[nxt] = arr[cur] + 1;
      q.push(nxt);
    }
  }
  for (int i = 1; i <= N; i++) cout << arr[i] << ' ';
  cout << '\n';
}