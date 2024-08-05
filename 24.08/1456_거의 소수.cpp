// https://www.acmicpc.net/problem/1456
#include <iostream>
#include <cmath>
#define MAX 10000001
using namespace std;
long A, B, ans;
bool p[MAX];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;
  for (int i = 2; i < MAX; i++) p[i] = true;
  for (int i = 2; i * i <= MAX; i++) {
    if (p[i]) {
      for (int j= i * i; j < MAX; j += i) {
        p[j]= false;
      }
    }            
  }
  for (int i = 2; i <= MAX; i++) {
    if (p[i]) {
      long num = i;
      while (num <= B / i) {
        if (A <= num * i) ans++;
        num *= i;
      }
    }
  }
  cout << ans << '\n';
}