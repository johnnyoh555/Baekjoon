// https://www.acmicpc.net/problem/11444
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
long N, mod = 1000000007;
unordered_map<long, vector<long>> um;

vector<long> ft(long x) {
  if (um.count(x))
    return um[x];
  auto a = ft(x / 2);
  auto b = ft((x + 1) / 2);
  return um[x] = {(a[0] * b[0] + a[1] * b[2]) % mod, (a[0] * b[1] + a[1] * b[3]) % mod, (a[2] * b[0] + a[3] * b[2]) % mod, (a[2] * b[1] + a[3] * b[3]) % mod};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  um[1] = {1, 1, 1, 0};
  cin >> N;
  cout << ft(N)[2] << '\n';
}