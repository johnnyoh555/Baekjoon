// https://www.acmicpc.net/problem/1039
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
string str;
int K, ans = -1;
bool vis[10][1000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str >> K;
  queue<pair<string, int>> q;
  q.push({str, 0});
  while (!q.empty()) {
    string s;
    int a;
    tie(s, a) = q.front(); q.pop();
    if (a == K) {
      int b = stol(s);
      if (b > ans) ans = b;
      continue;
    }
    for (int i = 0; i < str.size(); i++) {
      for (int j = i + 1; j < str.size(); j++) {
        string tmp = s;
        if (i == 0 && tmp[j] == '0') continue;
        swap(tmp[i], tmp[j]);
        int b = stol(tmp);
        if (vis[a][b]) continue;
        vis[a][b] = 1;
        q.push({tmp, a + 1});
      }
    }
  }
  cout << ans << '\n';
}