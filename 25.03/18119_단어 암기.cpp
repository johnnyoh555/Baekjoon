// https://www.acmicpc.net/problem/18119
#include <iostream>
using namespace std;
int N, M, arr[10000], flag = (1 << 26) - 1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string tmp; cin >> tmp;
    for (int j = 0; j < tmp.size(); j++) {
      arr[i] = (arr[i] | (1 << (tmp[j] - 'a')));
    }
  }
  for (int i = 0; i < M; i++) {
    int a, cnt = 0; char b; cin >> a >> b;
    if (a == 1) {
      flag -= (1 << (b - 'a'));
    } else {
      flag += (1 << (b - 'a'));
    }
    for (int j = 0; j < N; j++) {
      if (arr[j] == (arr[j] & flag)) cnt++;
    }
    cout << cnt << '\n';
  }
}
