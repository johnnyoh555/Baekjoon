// https://www.acmicpc.net/problem/14595
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, arr[1000001];
vector<pair<int, int>> v;

int uf(int f, int s) {
  if (arr[s] <= f) return arr[s];
  N--;
  return arr[s] = uf(f, s - 1);
}

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end(), compare);
  for (int i = 1; i <= N; i++) arr[i] = i;
  for (int i = 0; i < v.size(); i++) uf(v[i].first, v[i].second);
  cout << N << '\n';
}