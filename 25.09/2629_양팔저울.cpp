// https://www.acmicpc.net/problem/2629
#include <iostream>
#include <bitset>
using namespace std;
int n, T;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  bitset<40001> bs;
  bs[0] = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    bs |= bs << tmp;
  }
  cin >> T;
  for (int i = 0; i < T; i++) {
    int tmp; cin >> tmp;
    bool flag = 0;
    for (int i = 0; i + tmp <= 40000; i++) {
      if (bs[i] && bs[i + tmp]) {
        flag = 1;
        break;
      }
    }
    cout << (flag ? "Y\n" : "N\n");
  }
}