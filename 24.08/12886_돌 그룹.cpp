// https://www.acmicpc.net/problem/12886
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int A, B, C;
bool vis[1500][1500];
queue<tuple<int, int, int> > q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> C;
  vis[A][B] = 1;
  q.push({A, B, C});
  while (!q.empty()) {
    int a, b, c;
    tie(a, b, c) = q.front(); q.pop();
    if (a == b && b == c) {cout << "1\n"; return 0;}
    if (a < b) {
      int aa = a * 2;
      int bb = b - a;
      int cc = c;
      if (!vis[aa][bb]) {vis[aa][bb] = 1; q.push({aa, bb, cc});}
    }
    if (b < a) {
      int aa = a - b;
      int bb = b * 2;
      int cc = c;
      if (!vis[aa][bb]) {vis[aa][bb] = 1; q.push({aa, bb, cc});}
    }
    if (a < c) {
      int aa = a * 2;
      int bb = b;
      int cc = c - a;
      if (!vis[aa][bb]) {vis[aa][bb] = 1; q.push({aa, bb, cc});}
    }
    if (c < a) {
      int aa = a - c;
      int bb = b;
      int cc = c * 2;
      if (!vis[aa][bb]) {vis[aa][bb] = 1; q.push({aa, bb, cc});}
    }
    if (b < c) {
      int aa = a;
      int bb = b * 2;
      int cc = c - b;
      if (!vis[aa][bb]) {vis[aa][bb] = 1; q.push({aa, bb, cc});}
    }
    if (c < b) {
      int aa = a;
      int bb = b - c;
      int cc = c * 2;
      if (!vis[aa][bb]) {vis[aa][bb] = 1; q.push({aa, bb, cc});}
    }
  }
  cout << "0\n";
}