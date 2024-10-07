// https://www.acmicpc.net/problem/14863
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, t, v, arr[101][4], dp[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c || (a == c && b > d)) {swap(a, c); swap(b, d);}
    arr[i][0] = c; arr[i][1] = d;
    arr[i][2] = a; arr[i][3] = b;
    t += a; v += b;
  }
  K -= t;
  for (int i = 0; i < N; i++)
    for (int j = K; j >= arr[i][0] - arr[i][2]; j--)
      dp[j] = max(dp[j], dp[j - (arr[i][0] - arr[i][2])] + arr[i][1] - arr[i][3]); 
  cout << v + dp[K] << '\n';
}