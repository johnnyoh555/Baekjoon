// https://www.acmicpc.net/problem/5721
#include <iostream>
#include <algorithm>
using namespace std;
int du[100001], dr[100002], N, M, tmp;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    cin >> N >> M;
    if (!N && !M) break;
    for (int i = 2; i <= N + 1; i++) {
      for (int j = 2; j <= M + 1; j++) {
        cin >> tmp;
        dr[j] = max(dr[j - 1], dr[j - 2] + tmp);
      }
      du[i] = max(du[i - 2] + dr[M + 1], du[i - 1]);
    }
    cout << du[N + 1] << '\n';
  }
}