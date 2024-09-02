// https://www.acmicpc.net/problem/13144
#include <iostream>
using namespace std;
int N, st, en = 1, arr[100001];
long ans;
bool vis[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  vis[arr[0]] = 1;
  while (en < N) {
    if (!vis[arr[en]]) {
      vis[arr[en]] = 1;
    } else {
      while (1) {
        ans += en - st;
        if (arr[st] == arr[en]) {
          st++;
          break;
        }
        vis[arr[st]] = 0;
        st++;
      }
    }
    en++;
  }
  while (st < en) {ans += en - st; st++;}
  cout << ans << '\n';
}