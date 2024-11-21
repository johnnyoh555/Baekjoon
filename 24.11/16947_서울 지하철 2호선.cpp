// https://www.acmicpc.net/problem/16947
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, arr[3001], dp[3001];
vector<int> v[3001];
bool vis[3001];
queue<int> q;

void dfs(int x) {
  for (int y : v[x]) {
    if (arr[y] == 1 && !dp[y]) {
      dp[y] = dp[x] + 1;
      dfs(y);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
    arr[a]++;
    arr[b]++;
  }
  for (int i = 1; i <= N; i++) {
    if (arr[i] == 1) q.push(i);
  } 
  while (!q.empty()) {
    int now = q.front(); q.pop();
    vis[now] = 1;
    for (int nxt : v[now]) {
      if (!vis[nxt]) {
        if (--arr[nxt] == 1) {
          q.push(nxt);
        }
      }
    }
  }
  for (int i = 1; i <= N; i++)
    if (arr[i] > 1) dfs(i);
  for (int i = 1; i <= N; i++)
    cout << dp[i] << (i == N ? "\n" : " ");
}