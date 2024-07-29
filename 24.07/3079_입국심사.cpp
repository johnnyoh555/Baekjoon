// https://www.acmicpc.net/problem/3079
#include <iostream>
using namespace std;
long N, M, arr[100001], st, en;

bool check(long mid) {
  long cnt = 0;
  for (int i = 0; i < N; i++) {
    cnt += mid / arr[i];
    if (cnt >= M) break;
  }
  return cnt < M;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] * M > en) en = arr[i] * M;
  }
  en++;
  while (st < en) {
    long mid = (st + en) / 2;
    if (check(mid)) st = mid + 1;
    else en = mid;
  }
  cout << st << '\n';
}