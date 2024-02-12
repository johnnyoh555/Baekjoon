// https://www.acmicpc.net/problem/2293

#include <iostream>

using namespace std;

int coin[101];
long d[10001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  d[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> coin[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = coin[i]; j <= k; j++) {
      d[j] += d[j - coin[i]];
    }
  }
  cout << d[k] << '\n';
}

// #include <iostream>

// using namespace std;

// int coin[101];
// long d[10001];

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int n, k;
//   cin >> n >> k;
//   for (int i = 1; i <= n; i++) {
//     cin >> coin[i];
//   }
//   for (int j = 1; j <= n; j++) {
//     int v[10001] = {
//         0,
//     };
//     for (int i = 0; i <= k - coin[j]; i++) {
//       if (i && !d[i]) continue;
//       int tmp = i + coin[j];
//       while (tmp <= k) {
//         if (!d[i])
//           v[tmp]++;
//         else
//           v[tmp] += d[i];
//         tmp += coin[j];
//       }
//     }
//     for (int i = 1; i <= k; i++) {
//       d[i] += v[i];
//     }
//   }
//   cout << d[k] << '\n';
// }
