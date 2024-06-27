// https://www.acmicpc.net/problem/2470
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N, st, en, x, y, mn = 2e9 + 1;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	en = N - 1;
	while (st < en) {
		int mid = v[st] + v[en];
		if (abs(mid) < mn) {
			mn = abs(mid);
			x = st; y = en;
		}
		if (mid < 0) st++;
		else en--;
	}
	cout << v[x] << ' ' << v[y] << '\n';
}