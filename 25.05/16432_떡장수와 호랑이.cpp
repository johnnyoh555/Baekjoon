// https://www.acmicpc.net/problem/16432
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[1001][10];
int N, idx = 1;;
stack<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int m; cin >> m;
    for (int k = 0; k < m; k++) {
      int tmp; cin >> tmp;
      if (i == 0) {
        v[i][tmp].push_back(0);
      } else {
        for (int j = 1; j < 10; j++) {
          if (j == tmp || !v[i - 1][j].size()) continue;
          v[i][tmp].push_back(j);
        }
      }
    }
  }
  while (idx < 10 && !v[N - 1][idx].size()) idx++;
  if (idx == 10) {
    cout << "-1\n";
    return 0;
  } 
  while (N--) {
    s.push(idx);
    idx = v[N][idx][0];
  }
  while (!s.empty()) {
    cout << s.top() << '\n';
    s.pop();
  }
}
