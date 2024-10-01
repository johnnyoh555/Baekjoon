// https://www.acmicpc.net/problem/1756
#include <iostream>
#include <stack>
using namespace std;
int D, N, num = 2e9 + 1;
stack<int> oven;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> D >> N;
  for (int i = 0; i < D; i++) {
    int tmp; cin >> tmp;
    if (tmp < num) num = tmp;
    oven.push(num);
  }
  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    while (!oven.empty() && oven.top() < tmp) oven.pop();
    if (oven.empty()) {cout << "0\n"; return 0;}
    oven.pop();
  }
  cout << oven.size() + 1 << '\n';
}