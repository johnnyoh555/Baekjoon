// https://www.acmicpc.net/problem/17225
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A, B, N, b, r, bdx, rdx, cnt = 1;
vector<pair<int, int>> vb, vr;
vector<int> bns, rns;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> N;
  for (int i = 0; i < N; i++) {
    int x, y; char c; cin >> x >> c >> y;
    if (c == 'B') {
      vb.push_back({x, y});
    } else {
      vr.push_back({x, y});
    }
  }
  sort(vb.begin(), vb.end());
  sort(vr.begin(), vr.end());
  while (true) {
    if (bdx == vb.size()) b = 2e9;
    else b = max(b, vb[bdx].first);

    if (rdx == vr.size()) r = 2e9;
    else r = max(r, vr[rdx].first);
    if (b == 2e9 && r == 2e9) break;
    if (b <= r) {
      bns.push_back(cnt);
      b += A;
      if (vb[bdx].second == 1) bdx++;
      else vb[bdx].second--; 
    } else {
      rns.push_back(cnt);
      r += B;
      if (vr[rdx].second == 1) rdx++;
      else vr[rdx].second--; 
    }
    cnt++;
  }
  cout << bns.size() << '\n';
  for (int i = 0; i < bns.size() ; i++) {
    cout << bns[i] << (i == bns.size() - 1 ? '\n' : ' ');
  }
  cout << rns.size() << '\n';
  for (int i = 0; i < rns.size() ; i++) {
    cout << rns[i] << (i == rns.size() - 1 ? '\n' : ' ');
  }
}