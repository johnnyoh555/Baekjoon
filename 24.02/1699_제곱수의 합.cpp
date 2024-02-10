// https://www.acmicpc.net/problem/1699

#include <iostream>

using namespace std;

int d[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i <= N; i++) {
    d[i] = i;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j * j <= i && i - j * j >= 0; j++) {
      d[i] = min(d[i], d[i - j * j] + 1);
    }
  }
  cout << d[N] << '\n';
}

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int N;
//   cin >> N;
//   for (int i = 1; i <= 316; i++) {
//     int p = pow(i, 2);
//     d[p] = 1;
//   }
//   d[1] = 1;
//   d[2] = 2;
//   d[3] = 3;
//   for (int i = 5; i <= N; i++) {
//     if (!d[i]) {
//       int min = 0;
//       int k = i / 2;
//       for (int j = 1; j <= k; j++) {
//         int tmp = d[j] + d[i - j];
//         if (tmp < min || min == 0) min = tmp;
//       }
//       d[i] = min;
//     }
//   }
//   cout << d[N] << '\n';
// }