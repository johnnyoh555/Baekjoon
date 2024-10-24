// https://www.acmicpc.net/problem/2920
#include <iostream>
using namespace std;
int arr[8];
bool up, down;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 8; i++) {
    cin >> arr[i];
    if (!i) continue;
    if (arr[i - 1] != arr[i] - 1) up = 1;
    if (arr[i - 1] != arr[i] + 1) down = 1;
  }
  if (!up) cout << "ascending\n";
  else if (!down) cout << "descending\n";
  else cout << "mixed\n";
}