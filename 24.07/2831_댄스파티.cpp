// https://www.acmicpc.net/problem/2831
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N, ans;
vector<int> boy1, boy2, girl1, girl2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    if (tmp < 0) boy1.push_back(tmp);
    else boy2.push_back(tmp);
  }
  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    if (tmp < 0) girl1.push_back(tmp);
    else girl2.push_back(tmp);
  }
  sort(boy1.begin(), boy1.end());
  sort(girl1.begin(), girl1.end());
  sort(boy2.begin(), boy2.end(), greater<int>());
  sort(girl2.begin(), girl2.end(), greater<int>());
  int gp = 0, bp = 0;
  while (gp < girl2.size() && bp < boy1.size()) {
    if (abs(boy1[bp]) > girl2[gp]) {
      ans++;
      bp++;
    }
    gp++;
  }
  gp = 0; bp = 0;
  while (gp < girl1.size() && bp < boy2.size()) {
    if (abs(girl1[gp]) > boy2[bp]) {
      ans++;
      gp++;
    }
    bp++;
  }
  cout << ans << '\n';
}