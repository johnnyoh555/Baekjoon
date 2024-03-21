// https://www.acmicpc.net/problem/1539

#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int N, tmp;
long sum;
int h[250001];
set<int> S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		auto it = S.lower_bound(tmp);
		int a=0, b=0;
		if (it != S.begin()) a = h[*prev(it)];
		if (it != S.end()) b = h[*it];
		S.insert(tmp);
		h[tmp] = max(a, b) + 1;
	}
	for (int i = 0; i < N; i++) sum += h[i];
	cout << sum << '\n';
}