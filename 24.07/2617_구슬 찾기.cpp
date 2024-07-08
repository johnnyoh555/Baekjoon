// https://www.acmicpc.net/problem/2617
#include <iostream>
using namespace std;
int arr[100][100], N, M, cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    arr[a][b] = 1;
  }
  for (int k = 1; k <= N; k++) 
    for (int i = 1; i <= N; i++) 
      for (int j = 1; j <= N; j++) 
        if (arr[i][k] && arr[k][j]) arr[i][j] = 1;

  for (int i = 1; i <= N; i++) {
    int a = 0, b = 0;
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      if (arr[i][j]) a++;
      if (arr[j][i]) b++;
    }
    if (a > N / 2 || b > N / 2) cnt++;
  }
  cout << cnt << '\n';
}