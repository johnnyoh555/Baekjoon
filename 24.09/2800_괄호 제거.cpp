// https://www.acmicpc.net/problem/2800
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
string str;
stack<int> s;
vector<pair<int, int> > v;
vector<string> ans;
bool d[11];

void ft() {
  vector<int> tmp;
  for (int i = 0; i < v.size(); i++) {
    if (d[i]) {
      tmp.push_back({v[i].first});
      tmp.push_back({v[i].second});
    }
  }
  sort(tmp.begin(), tmp.end(), greater<int>());
  string ss = str;
  for (int i = 0; i < tmp.size(); i++)
    ss.erase(tmp[i], 1);
  if (ss == str) return;
  ans.push_back(ss);
}

void dfs(int dep) {
  if (dep == v.size()) {
    ft();
    return;
  }
  dfs(dep + 1);
  d[dep] = 1;
  dfs(dep + 1);
  d[dep] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') {
      s.push(i);
    } else if (str[i] == ')') {
      v.push_back({s.top(), i});
      s.pop();
    }
  }
  dfs(0);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << '\n';
}