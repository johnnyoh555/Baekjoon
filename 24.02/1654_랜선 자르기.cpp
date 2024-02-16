// https://www.acmicpc.net/problem/1654

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int k, n;
int arr[10001];

bool solve(ll m) {
	ll cur = 0;
	for (int i = 0; i < k; i++) cur += arr[i] / m;
	return cur >= n;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	ll s = 1;
	ll e = 0x7fffffff;
	while (s < e) {
		ll m = (s + e + 1) / 2;
		if (solve(m)) s = m;
		else e = m - 1;
	}
	cout << s << '\n';
}