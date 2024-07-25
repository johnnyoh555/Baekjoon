// https://www.acmicpc.net/problem/13422
#include <iostream>
using namespace std;
int arr[200001], T, N, M, K;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
      arr[i + N] = arr[i];
    }
    int st = 0, en = M - 1, sum = 0, cnt = 0;
    for (int i = 0; i <= en; i++) sum += arr[i];
    while (st < N) {
      if (sum < K) cnt++;
      sum -= arr[st]; st++;
      en++; sum += arr[en];
      if (M == N) break;
    }
    cout << cnt << '\n';
  }
}