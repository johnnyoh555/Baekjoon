// https://www.acmicpc.net/problem/1477
#include <iostream>
#include <algorithm>
using namespace std;
int arr[52], N, M, L;

bool check(int x) {
  int cnt = 0;
  for (int i = 1; i < N + 2; i++) {
    int dis = arr[i] - arr[i - 1];
    cnt += dis / x;
    if (dis % x == 0) cnt--;
  }
  return cnt >   M;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> L;
  for (int i = 0; i < N; i++) cin >> arr[i];
  arr[N] = 0; arr[N + 1] = L;
  sort(arr, arr + N + 2);
  int st = 1, en = L + 1;
  while (st < en) {
    int mid = (st + en) / 2;
    if (check(mid)) st = mid + 1;
    else en = mid;
  }
  cout << st << '\n';
}