// https://www.acmicpc.net/problem/16401

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M, N, max;
vector<int> v(1000001);

bool solve(long k) {
	long cur = 0;
	for (int i = 0; i < N; i++) cur += v[i] / k;
	return cur >= M;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	long s = 0;
	long e = 1000000001;
	while (s < e) {
		long k = (s + e + 1) / 2;
		if (solve(k)) s = k;
		else e = k - 1;
	}
	cout << s << '\n';
}